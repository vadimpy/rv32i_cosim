# syntax=docker/dockerfile:1
FROM alpine
WORKDIR /app
RUN apk add git perl python3 cmake make autoconf g++ flex bison ccache
RUN apk add numactl perl-doc
RUN git clone https://github.com/verilator/verilator
RUN git clone https://github.com/vadimpy/rv32i_cosim.git

WORKDIR /app/verilator
RUN git pull
RUN git tag
RUN git checkout master

RUN apk add flex-dev

RUN autoconf
RUN ./configure
RUN make -j3
RUN make install

WORKDIR /app/rv32i_cosim
