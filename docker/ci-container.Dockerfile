FROM ubuntu:24.04

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    gcc-13 g++-13 ninja-build git pkg-config libssl-dev zlib1g-dev curl \
    libyaml-cpp-dev libgtest-dev libbenchmark-dev \
    lcov gcovr \
    clang-format-20 clang-tidy \
    gnupg \
    && rm -rf /var/lib/apt/lists/* \
    && ldconfig \
    && update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-13 100 \
    && update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-13 100

RUN curl -L https://github.com/Kitware/CMake/releases/download/v4.3.2/cmake-4.3.2-linux-x86_64.tar.gz | \
    tar --strip-components=1 -xz -C /usr/local

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

RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-13 100 \
    && update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-13 100

WORKDIR /work

# stub for sudo and systemctl for the installation script
# RUN echo '#!/bin/sh\nexec "$@"' > /usr/local/bin/sudo && \
#     chmod +x /usr/local/bin/sudo
# RUN echo '#!/bin/sh\nexit 0' > /usr/local/bin/systemctl && \
#     chmod +x /usr/local/bin/systemctl

# RUN /work/tools/install_dlt.sh
