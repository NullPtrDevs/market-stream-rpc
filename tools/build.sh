#!/usr/bin/env bash

set -e

# shellcheck source=/dev/null
source "$(dirname "${BASH_SOURCE[0]}")/env.sh"

make_build_dir() {
    if [ "$CLEAN_BUILD" == "ON" ]; then
        if [ -d "$BUILD_DIR" ]; then
            rm -rf "$BUILD_DIR"
        fi
    fi
    mkdir -p "$BUILD_DIR"
}


build_project()
{
    echo -e "${GREEN}--------------------------------Start build---------------------------${NC}" 
    # clean and make build folder if needed
    make_build_dir
    
    cd "$BUILD_DIR" || exit 1

    CXX_FLAGS=""
    LDFLAGS=""

    if [ "${BUILD_COVERAGE}" == "ON" ]; then
        CXX_FLAGS="--coverage -O0 -g"
        LDFLAGS="--coverage"
    fi

    cmake -G "Ninja" \
        -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
        -DCMAKE_BUILD_TYPE="$BUILD_TYPE" \
        -DENABLE_THREAD_SANITIZER="$BUILD_THREAD_SANITIZE" \
        -DENABLE_ADDRESS_SANITIZER="$BUILD_ADDRESS_SANITIZE" \
        -DCMAKE_CXX_FLAGS="$CXX_FLAGS" \
        -DCMAKE_EXE_LINKER_FLAGS="$LDFLAGS" \
        ..
    cmake --build . --parallel $(nproc)

    echo -e "${GREEN}--------------------------------Build finished---------------------------${NC}" 
}

show_help() {
    echo "Usage: ./build.sh [options]"
    echo ""
    echo "Options:"
    echo "  -ts, --tsanitize  Enable thread sanitizer"
    echo "  -as, --atsanitize Enable address sanitizer"
    echo "  -cov, --coverage  Enable Code Coverage"
    echo "  -cl, --clean      Enable Code Coverage"
    echo "  -r, --release     Build in Release mode (default: Debug)"
    echo "  -h, --help        Show this help message"
    echo ""
    echo "Example: ./build.sh --clean --coverage"
    exit 0
}


if [[ "${BASH_SOURCE[0]}" == "${0}" ]]; then
    BUILD_TYPE="Debug"
    BUILD_THREAD_SANITIZE="OFF"
    BUILD_ADDRESS_SANITIZE="OFF"
    BUILD_COVERAGE="OFF"
    CLEAN_BUILD="OFF"

    while [[ "$#" -gt 0 ]]; do
        case $1 in
            -ts|--tsanitize) BUILD_THREAD_SANITIZE="ON"; shift ;;
            -as|--asanitize) BUILD_ADDRESS_SANITIZE="ON"; shift ;;
            -r|--release) BUILD_TYPE="Release"; shift ;;
            -cov|--coverage) BUILD_COVERAGE="ON"; shift ;;
            -cl|--clean) CLEAN_BUILD="ON"; shift ;;
            -h|--help) show_help ;;
            *) echo "Unknown parameter $1"; exit 1 ;;
        esac
    done
    # build_project "$BUILD_TYPE" "$BUILD_THREAD_SANITIZE" "$BUILD_ADDRESS_SANITIZE" "$BUILD_COVERAGE" "$CLEAN_BUILD"
    build_project
fi