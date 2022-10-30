export tests="fib fact bubble_sort"
export test_path="/app/rv32i_cosim/tests/c_tests"
export vtop="/app/rv32i_cosim/model/cpp_model/Vtop"
cd model
make test
