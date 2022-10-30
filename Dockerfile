# syntax=docker/dockerfile:1
FROM alpine
WORKDIR /app
RUN apk add git perl python3 cmake make autoconf g++ flex bison ccache flex-dev
RUN apk add numactl perl-doc
RUN git clone git@github.com:vadimpy/rv32i_cosim.git
WORKDIR /app/rv32i_cosim
