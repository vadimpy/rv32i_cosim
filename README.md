# rv32i_cosim
RV32i ISA Interpreter and verilog model cosimulation. Purposed to validate the behavior of 5-staged cycle-accurate model. <br>
Validation algorithm is as simple as following:
* Execute one instruction in an interpreter
* Clock the model unless model and interpreter registers states are equal, but not more than 15 clocks

This algorithm is not correct in general but enough to run several simple tests

#

## Dependencies
One may build docker image based on Alpine Linux with the following command
```sh
$ docker build .
```
There are two external dependencies:
* ELFIO - header-only library to process ELF binaries
* Verilator - translation of verilog models to efficient C++ simulator

To install them, one can simply run:
```sh
./prereqs.sh
```

#
## Tests

Surprisingly, ```build.sh``` and ```run_tests.sh``` scripts may be used to build and test code. There are three precompiled binaries in ```tests/c_tests```, which are cosimulated in tests. Currently ```bubble_sort``` test fails, ```fact``` and ```fib``` tests are supposed to pass validation. If one wants to create new tests, it is needed to have rv32i toolchain (at least gcc / clang) to produces binaries for tests. Several compiler options from ```cfg.yml``` should be used to compile tests correctly. Also there are sources of current tests in ```tests/c_tests```. To run tests one by one in verbose mode one should do the following
```sh
$ ./build.sh
$ ./cpp_model/Vtop tests/c_tests/<test_binary>
```

#

## Project sources
* emu - contains code of interpreter
* model - contains code of Verilog model
* sim - contains cosimulation code
