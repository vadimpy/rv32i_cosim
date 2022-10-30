#pragma once

#include <vector>
#include <string>
#include <cstdint>

namespace emu {

class Emu {

public:

    Emu();

    bool load_elf(const std::string &filepath);

    void step();
    bool not_finalized();

    void dump_regs();

    int get_reg(size_t i) const;
    int ram(size_t i) const;

    const uint8_t* raw_ram() const;

    int* regfile() {
        return regfile_;
    }

    int pc() const;
    int steps() const;

    int last_store_idx() const;

private:

    int last_store_idx_;

    int pc_;
    int regfile_[32];
    bool ecall_;
    int steps_;

    std::vector<uint8_t> ram_;

    bool store(int w, unsigned int idx, unsigned int bytes);
    bool load(int &w, unsigned int sp, unsigned int bytes, bool u = false);
};
} // namespace emu
