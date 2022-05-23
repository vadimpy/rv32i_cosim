#include "emu.hpp"

#include <cstring>
#include <elfio/elfio.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>

#define HEX(x)                                                                 \
    std::hex << "0x" << std::setfill('0') << std::setw(4) << x << std::dec

namespace emu {

Emu::Emu() : ram_(0x10000), steps_(0), last_store_idx_(0) {

    ecall_ = false;

    for (size_t i = 0; i < 32; i++) {
        regfile_[i] = 0;
    }

    for (size_t i = 0; i < ram_.size(); i++) {
        ram_[i] = 0;
    }
}

const uint8_t* Emu::raw_ram() const {
    return ram_.data();
}

int Emu::steps() const {
    return steps_;
}

int Emu::get_reg(size_t i) const {
    return regfile_[i];
}

int Emu::pc() const {
    return pc_;
}

int Emu::ram(size_t i) const {
    return ram_[i];
}

bool Emu::load_elf(const std::string &filepath) {
    ELFIO::elfio reader;
    reader.load(filepath);
    if (reader.get_class() != ELFIO::ELFCLASS32) {
        std::cerr << "Executable must be ELF32 class\n";
        return false;
    }

    if (reader.get_machine() != ELFIO::EM_RISCV) {
        std::cerr << "Machine must be RISCV\n";
        return false;
    }

    ELFIO::Elf_Half seg_num = reader.segments.size();
    std::cout << "Number of segments: " << seg_num << std::endl;
    for (int i = 0; i < seg_num; ++i) {
        const ELFIO::segment *pseg = reader.segments[i];
        const void *seg_data = pseg->get_data();
        size_t file_size = pseg->get_file_size();
        size_t virt_addr = pseg->get_virtual_address();
        std::memcpy(ram_.data() + virt_addr, seg_data, file_size);
    }

    pc_ = reader.get_entry() / 4;
    std::cout << "Entrypoint: " << HEX(pc_ * 4) << std::endl;
    return true;
}

void Emu::step() {
    ++steps_;
    int insn = 0;
    load(insn, 4 * pc_, 4);
    std::cout << steps_ << ' ';
    std::cout << HEX(pc_ * 4) << '\t';
    int opcode = insn & 0x7f;
    int funct3 = (insn >> 12) & 0x7;
    int imm = (insn >> 20);
    int rd = (insn >> 7) & 0x1f;
    int rs1 = (insn >> 15) & 0x1f;
    int rs2 = imm & 0x1f;
    int offset;

    switch (opcode) {
    case 0x03:
        switch (funct3) {
        case 0x0:
            std::cout << "lb x" << rd << " " << imm << "(x" << rs1 << ")"
                      << '\n';
            load(regfile_[rd], regfile_[rs1] + imm, 1);
            break;
        case 0x1: // lh
            std::cout << "lh x" << rd << " " << imm << "(x" << rs1 << ")"
                      << '\n';
            load(regfile_[rd], regfile_[rs1] + imm, 2);
            break;
        case 0x2: // lw
            std::cout << "lw x" << rd << " " << imm << "(x" << rs1 << ")"
                      << '\n';
            load(regfile_[rd], regfile_[rs1] + imm, 4);
            break;
        case 0x4:
            std::cout << "lbu x" << rd << " " << imm << "(x" << rs1 << ")"
                      << '\n';
            load(regfile_[rd], regfile_[rs1] + imm, 1, true);
            break;
        case 0x5:
            std::cout << "lhu x" << rd << " " << imm << "(x" << rs1 << ")"
                      << '\n';
            load(regfile_[rd], regfile_[rs1] + imm, 2, true);
            break;
        }
        break;
    case 0x13:
        switch (funct3) {
        case 0x0:
            std::cout << "addi x" << rd << " x" << rs1 << " " << imm << '\n';
            regfile_[rd] = regfile_[rs1] + imm;
            break;
        case 0x1: //
            std::cout << "slli x" << rd << " x" << rs1 << " " << imm << '\n';
            regfile_[rd] = regfile_[rs1] << imm;
            break;
        case 0x2:
            std::cout << "slti x" << rd << " x" << rs1 << " " << imm << '\n';
            if (regfile_[rs1] < imm) {
                regfile_[rd] = 1;
            } else {
                regfile_[rd] = 0;
            }
            break;
        case 0x3:
            std::cout << "sltiu x" << rd << " x" << rs1 << " "
                      << (unsigned int)(imm & 0xfff) << '\n';
            if (regfile_[rs1] < ((unsigned int)(imm & 0xfff))) {
                regfile_[rd] = 1;
            } else {
                regfile_[rd] = 0;
            }
            break;
        case 0x4:
            std::cout << "xori x" << rd << " x" << rs1 << " " << imm << '\n';
            regfile_[rd] = regfile_[rs1] ^ imm;
            break;
        case 0x5:
            if ((imm & 0xf00) == 0) {
                std::cout << "slri x" << rd << " x" << rs1 << " " << imm
                          << '\n';
                regfile_[rd] = regfile_[rs1] >> imm;
            } else {
                std::cout << "srai x" << rd << " x" << rs1 << " "
                          << (imm & 0x1f) << '\n';
                regfile_[rd] = regfile_[rs1] >> (imm & 0x1f);
            }
            break;
        case 0x6:
            std::cout << "ori x" << rd << " x" << rs1 << " " << imm << '\n';
            regfile_[rd] = regfile_[rs1] | imm;
            break;
        case 0x7:
            std::cout << "andi x" << rd << " x" << rs1 << " " << imm << '\n';
            regfile_[rd] = regfile_[rs1] & imm;
            break;
        }
        break;
    case 0x17: // auipc
        imm = ((insn >> 12) << 12);
        std::cout << "auipc x" << rd << " " << imm << '\n';
        regfile_[rd] = pc_ * 4 + imm;
        break;
    case 0x23:
        imm = (imm >> 5) << 5 | rd;
        switch (funct3) {
        case 0x0:
            std::cout << "sb x" << rs2 << " " << imm << "("
                      << "x" << rs1 << ")" << '\n';
            store(regfile_[rs2], regfile_[rs1] + imm, 1);
            break;
        case 0x1:
            std::cout << "sh x" << rs2 << " " << imm << "("
                      << "x" << rs1 << ")" << '\n';
            store(regfile_[rs2], regfile_[rs1] + imm, 2);
            break;
        case 0x2:
            std::cout << "sw x" << rs2 << " " << imm << "("
                      << "x" << rs1 << ")" << '\n';
            store(regfile_[rs2], regfile_[rs1] + imm, 4);
            break;
        }
        break;
    case 0x33:
        switch (funct3) {
        case 0x0:
            if ((insn >> 25) == 0) {
                std::cout << "add x" << rd << " x" << rs1 << " x" << rs2
                          << '\n';
                regfile_[rd] = regfile_[rs1] + regfile_[rs2];
            } else {
                std::cout << "sub x" << rd << " x" << rs1 << " x" << rs2
                          << '\n';
                regfile_[rd] = regfile_[rs1] - regfile_[rs2];
            }
            break;
        case 0x1:
            std::cout << "sll x" << rd << " x" << rs1 << " x"
                      << (regfile_[rs2] & 0x1f) << '\n';
            regfile_[rd] = regfile_[rs1] << (regfile_[rs2] & 0x1f);
            break;
        case 0x2:
            std::cout << "slt x" << rd << " x" << rs1 << " x" << rs2 << '\n';
            if (regfile_[rs1] < regfile_[rs2]) {
                regfile_[rd] = 1;
            } else {
                regfile_[rd] = 0;
            }
            break;
        case 0x3:
            std::cout << "sltu x" << rd << " x" << rs1 << " x" << rs2 << '\n';
            if (regfile_[rs1] < (unsigned int)regfile_[rs2]) {
                regfile_[rd] = 1;
            } else {
                regfile_[rd] = 0;
            }
            break;
        case 0x4:
            std::cout << "xor x" << rd << " x" << rs1 << " x" << rs2 << '\n';
            regfile_[rd] = regfile_[rs1] ^ regfile_[rs2];
            break;
        case 0x5:
            if ((insn >> 25) == 0) {
                std::cout << "srl x" << rd << " x" << rs1 << " x"
                          << (regfile_[rs2] & 0x1f) << '\n';
                regfile_[rd] =
                    ((unsigned int)regfile_[rs1]) >> (regfile_[rs2] & 0x1f);
            } else {
                std::cout << "sra x" << rd << " x" << rs1 << " x"
                          << (regfile_[rs2] & 0x1f) << '\n';
                regfile_[rd] = regfile_[rs1] >> (regfile_[rs2] & 0x1f);
            }
            break;
        case 0x6:
            std::cout << "OR x" << rd << " x" << rs1 << " x" << rs2 << '\n';
            regfile_[rd] = regfile_[rs1] | regfile_[rs2];
            break;
        case 0x7:
            std::cout << "and x" << rd << " x" << rs1 << " x" << rs2 << '\n';
            regfile_[rd] = regfile_[rs1] & regfile_[rs2];
            break;
        }
        break;
    case 0x37:
        std::cout << "lui x" << rd << " " << ((insn >> 12) & 0xfffff) << '\n';
        regfile_[rd] = ((insn >> 12) & 0xfffff) << 12;
        break;
    case 0x63: // Branch case
        offset = ((insn >> 25) << 5) + ((insn >> 7) & 0x1f) - 1;
        if (offset > 0) {
            offset++;
        }
        switch (funct3) {
        case 0x0:
            std::cout << "beq x" << rs1 << " x" << rs2 << " " << offset << '\n';
            if (regfile_[rs1] == regfile_[rs2]) {
                pc_ = pc_ + (offset / 4) - 1;
            }
            break;
        case 0x1:
            std::cout << "bne x" << rs1 << " x" << rs2 << " " << offset << '\n';
            if (regfile_[rs1] != regfile_[rs2]) {
                pc_ = pc_ + (offset / 4) - 1;
            }
            break;
        case 0x4:
            std::cout << "blt x" << rs1 << " x" << rs2 << " " << offset << '\n';
            if (regfile_[rs1] < regfile_[rs2]) {
                pc_ = pc_ + (offset / 4) - 1;
            }
            break;
        case 0x5:
            std::cout << "bge x" << rs1 << " x" << rs2 << " " << offset << '\n';
            if (regfile_[rs1] >= regfile_[rs2]) {
                pc_ = pc_ + (offset >> 2) - 1;
            }
            break;
        case 0x6:
            std::cout << "bltu x" << rs1 << " x" << rs2 << " " << offset
                      << '\n';
            if (regfile_[rs1] < (unsigned)regfile_[rs2]) {
                pc_ = pc_ + (offset / 4) - 1;
            }
            break;
        case 0x7:
            std::cout << "bgeu x" << rs1 << " x" << rs2 << " " << offset
                      << '\n';
            if (regfile_[rs1] >= (unsigned)regfile_[rs2]) {
                pc_ = pc_ + (offset >> 2) - 1;
            }
            break;
        }
        break;
    case 0x67: // jalr
        std::cout << "jalr x" << rd << " x" << rs1 << " " << imm << std::endl;
        regfile_[rd] = (pc_ + 1) << 2;
        pc_ = (regfile_[rs1] + imm) >> 2;
        pc_ = pc_ - 1;
        break;
    case 0x6f: // jal
        imm = (insn >> 30) << 20;
        imm = imm | (((insn >> 12) & 0xff) << 12); // insn[19:12]
        imm = imm | (((insn >> 20) & 0x1) << 11);  // insn[11]
        imm = imm | (((insn >> 21) & 0x3ff) << 1); // insn[10:1]
        std::cout << "jal x" << rd << " " << imm << std::endl;
        regfile_[rd] = (pc_ + 1) << 2;
        pc_ = pc_ + (imm >> 2) - 1;
        break;
    case 0x73:
        std::cout << "ecall" << '\n';
        ecall_ = true;
        break;
    }
    regfile_[0] = 0;
    pc_++;
}

bool Emu::not_finalized() { return (!ecall_); }

void Emu::dump_regs() {
    std::cout << "Value of registers: \n" << std::endl;
    for (int i = 0; i < 32; i++) {
        std::cout << "x" << i << " " << regfile_[i] << std::endl;
    }
}

bool Emu::store(int w, unsigned int idx, unsigned int bytes) {
    for (unsigned int i = 0; i < bytes; i++) {
        ram_[idx + i] = (unsigned char)(w >> (8 * i)) & 0xff;
    }
    last_store_idx_ = idx / 4;
    return true;
}

int Emu::last_store_idx() const {
    return last_store_idx_;
}

bool Emu::load(int &w, unsigned int sp, unsigned int bytes, bool u) {
    w = 0;
    for (unsigned int i = 0; i < bytes; i++) {
        w = w | ((unsigned int)ram_[sp + i]) << (8 * i);
    }

    if (!u) {
        if ((ram_[sp + bytes - 1] >> 7) == 1) {
            for (int i = 4; i > bytes; i--) {
                w = w | 0xff << (8 * (i - 1));
            }
        }
    }
    return true;
}
} // namespace emu
