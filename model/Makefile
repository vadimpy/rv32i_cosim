include_path=include
regfile=modules/regfile
ram=modules/ram
fetch=modules/fetch
decoder=modules/decoder
exec=modules/exec
mem=modules/mem
writeback=modules/writeback
top=modules/top/top.v
sim=../sim/sim.cpp
cpp_include=/Users/vadimpyx/dev/rv32i_interp/include
emu=/Users/vadimpyx/dev/rv32i_interp/emu

build:
	@verilator -CFLAGS '-I${cpp_include} -I${emu}' -cc -Mdir cpp_model \
		-I${include_path} \
		-I${ram} \
		-I${regfile} \
		-I${fetch} \
		-I${decoder} \
		-I${exec} \
		-I${mem} \
		-I${writeback} \
		--exe --build  --public ${sim} ${emu}/emu.cpp ${top}
