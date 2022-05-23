#include "Vtop.h"
#include <verilated.h>
#include <memory>
#include <iostream>

int main() {

    VModule<Vtop> top;

    top->rst_n = 0;
    top->clk = 0;
    top->count = 0;
    top->eval();

    for (size_t i = 0; i < 10; ++i) {
        top.tick();
        std::cout << int(top->count) << std::endl;
    }

    return 0;
}
