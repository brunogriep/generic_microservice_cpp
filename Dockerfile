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

# Install gRPC
RUN git clone --recurse-submodules -b v1.66.0 --depth 1 --shallow-submodules https://github.com/grpc/grpc && \
    cd grpc && \
    mkdir -p cmake/build && \
    cd cmake/build && \
    cmake -DgRPC_INSTALL=ON -DgRPC_BUILD_TESTS=OFF -DCMAKE_INSTALL_PREFIX=/usr/local ../.. && \
    make -j 4 && \
    make install && \
    cd ../../..

# Install glog
RUN git clone https://github.com/google/glog.git && \
    cd glog && \
    cmake -S . -B build -G "Unix Makefiles" && \
    cmake --build build && \
    cmake --build build --target install && \
    cd ..

# Install SQLite ORM
RUN git clone https://github.com/fnc12/sqlite_orm.git sqlite_orm && \
    cd sqlite_orm && \
    cmake -B build && \
    cmake --build build --target install && \
    cd ..

ADD . /workspace
WORKDIR /workspace

RUN conan profile detect --force
RUN conan install . --build=missing --settings=build_type=Debug
