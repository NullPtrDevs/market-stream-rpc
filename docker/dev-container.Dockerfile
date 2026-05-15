ARG BASE_IMAGE=ubuntu:24.04
FROM ${BASE_IMAGE}

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

WORKDIR /work
RUN chmod 777 /work

RUN echo "set auto-load safe-path /" >> /etc/gdb/gdbinit

CMD ["/bin/bash"]
