#include <verilated.h>
#include <iostream>
#include <cstdint>

#include "sim.hpp"
#include "emu.hpp"

class State {
public:

    template<typename T>
    void set(const T& regs, uint32_t store_idx, uint32_t store_val) {
        store_idx_ = store_idx;
        store_val_ = store_val;
        for (size_t i = 0; i < 32; ++i)
            regs_[i] = regs[i];
    }

    State& operator=(const State& r) {
        store_idx_ = r.store_idx_;
        store_val_ = r.store_val_;
        for (size_t i = 0; i < 32; ++i)
            regs_[i] = r.regs_[i];
        return *this;
    }

    bool operator==(const State& r) const {
        for (size_t i = 0; i < 32; ++i)
            if (regs_[i] != r.regs_[i])
                return false;

        if (store_idx_ != r.store_idx_)
            return false;

        if (store_val_ != r.store_val_)
            return false;

        return true;
    }

    void dump_mismatch(const State& r) const {
        std::cerr << '\n';
        for (size_t i = 0; i < 32; ++i)
            if (regs_[i] != r.regs_[i])
                std::cerr << 'x' << i << ": " << regs_[i] << " != " << r.regs_[i] << '\n';
        if (store_idx_ != r.store_idx_)
            std::cerr << "Store addr: " << HEX(store_idx_ * 4) << " != " << HEX(r.store_idx_ * 4) << '\n';
        if (store_val_ != r.store_val_)
            std::cerr << "Store val: " << store_val_ << " != " << r.store_val_ << '\n';
        std::cerr << '\n';
    }

private:
    uint32_t regs_[32];
    uint32_t store_idx_;
    uint32_t store_val_;
};

enum Result {
    OK = 0,
    SOFT_FAIL = 1,
    HARD_FAIL = 2
};

template <typename T, size_t MaxAttempts>
class Validator {
public:
    Validator(const T& state) : state_(state) {}

    void update_state(const T& state) {
        state_ = state;
    }

    Result compare(const T& state) {
        static int attempts = 0;
        if (state == state_) {
            attempts = 0;
            return OK;
        }

        ++attempts;
        if (attempts <= MaxAttempts)
            return SOFT_FAIL;

        attempts = 0;
        return HARD_FAIL;
    }

private:
    T state_;
};

int main(int argc, char* argv[]) {

    sim::Model model;
    model.reset_regs();
    model.load_elf(argv[1]);
    model.regfile(2) = 0x7000;
    model.regfile(1) = 0x4000;

    State model_state;
    model_state.set(model.regfile_ref(), model.last_store_idx(), model.ram(model.last_store_idx()));

    emu::Emu cpu_emu;
    cpu_emu.load_elf(argv[1]);
    cpu_emu.regfile()[2] = 0x7000;
    cpu_emu.regfile()[1] = 0x4000;

    State emu_state;
    emu_state.set(cpu_emu.regfile(), cpu_emu.last_store_idx(), cpu_emu.ram(cpu_emu.last_store_idx()));

    Validator<State, 15> state_validator(emu_state);
    Validator<std::pair<uint32_t, uint32_t>, 10> mem_validator(std::make_pair(cpu_emu.last_store_idx(), cpu_emu.ram(cpu_emu.last_store_idx())));

    // while (true) {
    //     model.clock();
    //     for (int i = 0; i < 10; ++i)
    //         std::cout << model.ram(i) << ' ';
    //     std::cout << "\n";
    //     std::cin.get();
    // }

    while (true) {
        std::cin.get();
        std::cout << "model clocks: " << model.ticks() / 2 << "\temu steps: " << cpu_emu.steps() << '\n';
        Result val_res = state_validator.compare(model_state);
        std::cout << "Emu pc " << HEX(cpu_emu.pc() * 4) << '\n';
        switch (val_res) {
        case OK:
            std::cout << "OK\n";
            std::cout << "------------\n\n";
            if (cpu_emu.not_finalized()) {
                model.clock();
                model_state.set(model.regfile_ref(), 0, 0);// model.last_store_idx(), model.ram(model.last_store_idx()));
                cpu_emu.step();
                emu_state.set(cpu_emu.regfile(), 0, 0);// cpu_emu.last_store_idx(), cpu_emu.ram(cpu_emu.last_store_idx()));
                state_validator.update_state(emu_state);
            } else {
                for (int i = 0; i < 10; ++i)
                    std::cout << model.ram(i) << ' ';
                std::cout << "\nSuccess!\n";
                return 0;
            }
            break;
        case SOFT_FAIL:

            // if ((cpu_emu.ram(cpu_emu.last_store_idx()) != model.ram(model.last_store_idx())) || (model.last_store_idx() != cpu_emu.last_store_idx())) {
            //     cpu_emu.step();
            //     std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxx\n";
            //     emu_state.set(cpu_emu.regfile(), cpu_emu.last_store_idx(), cpu_emu.ram(cpu_emu.last_store_idx()));
            // }

            model_state.dump_mismatch(emu_state);
            std::cout << "SOFT FAIL\n";
            std::cout << "------------\n\n";
            model.clock();
            model_state.set(model.regfile_ref(), 0, 0); // model.last_store_idx(), model.ram(model.last_store_idx()));
            break;
        case HARD_FAIL:
            std::cerr << "HARD FAIL\n";
            std::cout << "------------\n\n";
            return 0;
        }
    }

    return 0;
}
