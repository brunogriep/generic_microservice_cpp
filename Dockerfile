FROM ubuntu:22.04

RUN apt-get update -qq && \
    export DEBIAN_FRONTEND=noninteractive

RUN apt-get install -y \
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

RUN apt-get autoremove -y && apt-get clean && \
    rm -rf /var/lib/apt/lists/*

RUN pip3 install conan

# Include project
ADD . /workspace
WORKDIR /workspace

CMD ["/bin/bash"]
