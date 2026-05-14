FROM ci-container:latest

USER root

RUN apt-get update && apt-get install -y --no-install-recommends \
    gdb \
    valgrind \
    strace \
    ltrace \
    build-essential \
    pkg-config \
    tcpdump \
    iputils-ping \
    curl \
    bash-completion \
    nano \
    pre-commit \
    gh \
    mc \
    tmux \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace

RUN echo "set auto-load safe-path /" >> /etc/gdb/gdbinit

RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-13 100 \
    && update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-13 100

ENV GRPC_VERBOSITY=ERROR
ENV GRPC_TRACE=all

CMD ["/bin/bash"]
