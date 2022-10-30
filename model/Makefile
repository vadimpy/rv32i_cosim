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
