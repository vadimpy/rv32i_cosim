#include <fstream>
#include <iostream>
#include <string>

#include "emu.hpp"

int main(int argc, char *argv[]) {

    emu::Emu cpu_emu;
    cpu_emu.load_elf(argv[1]);

    int steps = std::stoi(argv[2]);

    cpu_emu.regfile()[2] = 0x7000;
    cpu_emu.regfile()[1] = 0x4000;

    if (steps == 0) {
        while (cpu_emu.not_finalized()) {
            cpu_emu.step();
        } 
    } else {
        for (size_t i = 0; i < steps; ++i) {
            cpu_emu.step();
        }
    }

    cpu_emu.dump_regs();
    for (int i = 0; i < 10; ++i)
        std::cout << reinterpret_cast<const uint32_t*>(cpu_emu.raw_ram())[i] << ' ';
    std::cout << std::endl;
    return 0;
}
