include_path=include
regfile=modules/regfile
ram=modules/ram
fetch=modules/fetch
decoder=modules/decoder
exec=modules/exec
mem=modules/mem
writeback=modules/writeback
top=modules/top/top.v
sim=/app/rv32i_cosim/sim/sim.cpp
cpp_include=/app/rv32i_cosim/include
emu=/app/rv32i_cosim/emu

build:
	@verilator -CFLAGS '-std=c++14 -I${cpp_include} -I${emu}' -cc -Mdir cpp_model \
		-I${include_path} \
		-I${ram} \
		-I${regfile} \
		-I${fetch} \
		-I${decoder} \
		-I${exec} \
		-I${mem} \
		-I${writeback} \
		--exe --build  --public ${sim} ${emu}/emu.cpp ${top}
