# Install verilator
cd verilator
git pull
git checkout master
autoconf
./configure
make -j3
make install

# Install ELFIO
cd ../ELFIO
git pull
git checkout master
cp -r elfio ../include
