#include <verilated.h>
#include <iomanip>

#include "tools/common.hpp"
#include "vmodule.hpp"
#include "Vtop.h"
#include "Vtop_top.h"

#define HEX(x)                                                                 \
    std::hex << "0x" << std::setfill('0') << std::setw(4) << x << std::dec

namespace sim {

class Model : public VModule<Vtop> {

private:
    auto& top() {
        return (*this)->top;
    }

public:

    using VModule<Vtop>::VModule;

    auto& ram(size_t i) {
        return top()->ram__DOT__data[i];
    }

    auto& ram_ref() {
        return top()->ram__DOT__data;
    }

    auto& regfile(size_t i) {
        return top()->regfile__DOT__regs[i];
    }

    auto& regfile_ref() {
        return top()->regfile__DOT__regs;
    }

    auto& pc() {
        return top()->fetch__DOT__pc;
    }

    void reset_regs() {
        for (size_t i = 0; i < 32; ++i)
            regfile(i) = 0;
        pc() = 0;
    }

    uint32_t last_store_idx() {
        return top()->ram__DOT__last_w_addr;
    }

    void eval() {
        (*this)->eval();
    }

    void load_elf(const std::string& path) {
        auto elf_data = simtools::get_elf_data(path);
        for (auto& seg: elf_data.segs) {
            uint32_t seg_word_base = seg.start_addr / 4;
            for (size_t i = 0; i < seg.data.size(); ++i)
                ram(seg_word_base + i) = seg.data[i];
            std::cout << std::endl;
        }
        pc() = elf_data.entry;
        eval();
    }

    uint32_t fetch_insn() {
        return top()->fetch__DOT__insn;
    }

    void dump_writeback() {
        std::cout << "wb_regfile_w_data: " << wb_regfile_w_data() << " (" << HEX(wb_regfile_w_data()) << ")\n";
        std::cout << "wb_regfile_w_reg: " << wb_regfile_w_reg() << '\n';
    }

    uint32_t wb_regfile_w_data() {
        return top()->writeback__DOT__regfile_w_data;
    }

    uint32_t wb_regfile_w_en() {
        return top()->writeback__DOT__regfile_w_en;
    }

    uint32_t wb_regfile_w_reg() {
        return top()->writeback__DOT__regfile_w_reg;
    }

    uint32_t regfile_w_reg_name() {
        return top()->regfile__DOT__w_reg_name;
    }

    uint32_t regfile_w_reg_val() {
        return top()->regfile__DOT__w_reg_val;
    }
};
}
