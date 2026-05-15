FROM ubuntu:24.04

ARG DEBIAN_FRONTEND=noninteractive

# Install development tools and libraries
RUN apt-get update && apt-get install -y --no-install-recommends \
    gcc-13 \
    g++-13 \
    make \
    ninja-build \
    git \
    pkg-config \
    libssl-dev \
    zlib1g-dev \
    curl \
    libyaml-cpp-dev \
    libgtest-dev \
    libbenchmark-dev \
    lcov \
    gcovr \
    python3 \
    clang-format-20 \
    clang-tidy-20 \
    gnupg \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/*

# Configure alternatives for compilers and tools
RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-13 100 \
    && update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-13 100 \
    && update-alternatives --install /usr/bin/clang-format clang-format /usr/bin/clang-format-20 100 \
    && update-alternatives --install /usr/bin/clang-tidy clang-tidy /usr/bin/clang-tidy-20 100 \
    && update-alternatives --install /usr/bin/run-clang-tidy run-clang-tidy /usr/bin/run-clang-tidy-20 100 \
    && ldconfig

# Install CMake 4.3.2
RUN curl -L https://github.com/Kitware/CMake/releases/download/v4.3.2/cmake-4.3.2-linux-x86_64.tar.gz | \
    tar --strip-components=1 -xz -C /usr/local

# Install gRPC
WORKDIR /grpc-build
RUN git clone --recurse-submodules -b v1.80.0 --depth 1 --shallow-submodules https://github.com/grpc/grpc .

RUN cmake -B build -G Ninja \
    -DCMAKE_CXX_COMPILER=g++-13 \
    -DCMAKE_C_COMPILER=gcc-13 \
    -DCMAKE_BUILD_TYPE=Release \
    -DgRPC_INSTALL=ON \
    -DgRPC_BUILD_TESTS=OFF \
    -DgRPC_SSL_PROVIDER=package \
    -DgRPC_ZLIB_PROVIDER=package \
    -DgRPC_BUILD_GRPC_CLI=ON \
    -DCMAKE_INSTALL_PREFIX=/usr/local \
    && cmake --build build --target install

# Install DLT Daemon and concurrentqueue
RUN git clone https://github.com/COVESA/dlt-daemon.git /tmp/dlt-install \
    && cd /tmp/dlt-install \
    && git checkout v3.0.0 \
    && cmake -B build -G Ninja \
       -DCMAKE_BUILD_TYPE=Release \
       -DCMAKE_INSTALL_PREFIX=/usr/local \
       -DWITH_SYSTEMD=OFF \
       -DWITH_DLT_TESTS=OFF \
    && cmake --build build --target install \
    && ldconfig \
    && rm -rf /tmp/dlt-install

RUN git clone -b v1.0.5 --depth 1 https://github.com/cameron314/concurrentqueue.git /tmp/cq \
    && cd /tmp/cq \
    && cp -r /tmp/cq/*.h /usr/local/include/ \
    && rm -rf /tmp/cq

WORKDIR /work

# stub for sudo and systemctl for the installation script
# RUN echo '#!/bin/sh\nexec "$@"' > /usr/local/bin/sudo && \
#     chmod +x /usr/local/bin/sudo
# RUN echo '#!/bin/sh\nexit 0' > /usr/local/bin/systemctl && \
#     chmod +x /usr/local/bin/systemctl

# RUN /work/tools/install_dlt.sh
