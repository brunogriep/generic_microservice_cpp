FROM ubuntu:22.04

RUN DEBIAN_FRONTEND=noninteractive apt-get update -qq && \
    DEBIAN_FRONTEND=noninteractive apt-get install -qqy \
    build-essential \
    libtool \
    pkg-config \
    clang-tidy \
    clang-format \
    cmake \
    g++ \
    gcc \
    gcovr \
    gdb \
    make \
    ninja-build \
    parallel \
    python3 \
    python3-pip

RUN pip3 install conan
RUN conan profile detect --force

COPY conanfile.py .

RUN conan install . --build=missing -s build_type=Debug

ADD . /workspace
WORKDIR /workspace
