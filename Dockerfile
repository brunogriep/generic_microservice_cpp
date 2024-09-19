FROM ubuntu:22.04

RUN DEBIAN_FRONTEND=noninteractive apt-get update -qq && \
    DEBIAN_FRONTEND=noninteractive apt-get install -qqy \
    autoconf \
    build-essential \
    clang-tidy \
    clang-format \
    cmake \
    g++ \
    gcc \
    gcovr \
    git \
    libtool \
    libprotobuf-dev \
    libgtest-dev \
    libsqlite3-dev \
    make \
    pkg-config \
    protobuf-compiler \
    python3 \
    python3-pip

RUN pip3 install conan

# install grpc
RUN git clone --recurse-submodules -b v1.66.0 --depth 1 --shallow-submodules https://github.com/grpc/grpc && \
    cd grpc && \
    mkdir -p cmake/build && \
    cd cmake/build && \
    cmake -DgRPC_INSTALL=ON -DgRPC_BUILD_TESTS=OFF -DCMAKE_INSTALL_PREFIX=/usr/local ../.. && \
    make -j 4 && \
    make install && \
    cd ../../..

ADD . /workspace
WORKDIR /workspace

RUN conan profile detect --force
RUN conan install . --build=missing --settings=build_type=Debug
