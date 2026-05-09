#!/usr/bin/env bash

set -e

show_help() {
    echo -e "${GREEN}Build project and run benchmark tests"
    echo "Usage: build_and_run_benchmark_tests.sh [options]"
    echo "-------------------------------------------------------------------"
    echo "Options:"
    echo "  -cl, --clean      Generate coverage"
    echo "  -h, --help          Show this help message"
    echo -e "-------------------------------------------------------------------${NC}"
    exit 0
}

# shellcheck source=/dev/null
source "$(dirname "${BASH_SOURCE[0]}")/env.sh"

# This variables uses by build_project function.
# Do no change the names!
USE_THREAD_SANITIZER="OFF"
USE_ADDRESS_SANITIZER="OFF"
USE_COVERAGE="OFF"
USE_COVERAGE_HTML="OFF"
BUILD_TYPE="Release"
CLEAN_BUILD="OFF"


while [[ "$#" -gt 0 ]]; do
        case $1 in
            -cl|--clean) CLEAN_BUILD="ON"; shift ;;
            -h|--help) show_help ;;
            *) echo "Unknown parameter $1"; exit 1 ;;
        esac
    done


# shellcheck source=/dev/null
source "$SCRIPT_DIR/build.sh"
build_project

echo -e "${GREEN}--------------------------------Start benchmark tests---------------------------${NC}"
find "$BUILD_DIR/src" -type f -name "benchmark_*" -executable -exec {} \;