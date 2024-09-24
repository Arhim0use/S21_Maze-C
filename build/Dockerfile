FROM ubuntu:rolling

RUN apt-get update && apt-get upgrade -y && \
    apt-get install -y \
    valgrind \
    bash \
    build-essential \
    cppcheck \
    clang \
    libpcre3-dev \
    clang-tools \
    libgtest-dev \
    gcc \
    cppcheck \
    checkinstall \
    check \
    pkg-config

RUN pkg-config --cflags --libs check


WORKDIR /test

COPY . /test

WORKDIR "/test/src"

ENTRYPOINT ["make", "test", "valgrind"]