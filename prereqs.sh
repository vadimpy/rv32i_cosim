git submodule update --init --recursive

# Install verilator
cd verilator
autoconf
./configure
make -j3
make install

# Install ELFIO
cd ../ELFIO
cp -r elfio ../include
