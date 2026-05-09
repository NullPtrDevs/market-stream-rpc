#!/usr/bin/env bash

# Generate coverage report, installed lcov needed.

set -e

show_help() {
    echo "Build project, run tests and generate coverage report"
    echo "Usage: ./build.sh [options]"
    echo "-------------------------------------------------------------------"
    echo "Options:"
    echo "  -ts, --tsanitize    Build with thread sanitizers"
    echo "  -as, --asanitize    Build with thread sanitizers"
    echo "  -r, --release       Build in Release mode (default is Debug)"
    echo "  -gh, --html         Generate html report"
    echo "  -c, --coverage      Generate coverage"
    echo "  -h, --help          Show this help message"
    echo "-------------------------------------------------------------------"
    echo "Please be aware that flag -c can conflict with -s."
    echo "Sanitizer can recognize coverage library as an error. Better don't use them both."
    echo "Do not use -ts with -as together. Compiler can use only one option."
    echo "If they used both, -as will be set as default."
    exit 0
}

remove_build_dir() {
    if [ -d "$BUILD_DIR" ]; then
        rm -rf "$BUILD_DIR"
    fi
}

SCRIPT_DIR=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)

PROJECT_ROOT=$(cd "$SCRIPT_DIR/.." && pwd)

BUILD_DIR="$PROJECT_ROOT/build"
COVERAGE_DIR="$PROJECT_ROOT/coverage_report"

USE_THREAD_SANITIZER="OFF"
USE_ADDRESS_SANITIZER="OFF"
USE_COVERAGE="OFF"
USE_COVERAGE_HTML="OFF"
BUILD_TYPE="Debug"

echo "--------------------------------Setup coverage dir---------------------------" 

# prepare coverage folder
rm -rf "${COVERAGE_DIR}"
mkdir "${COVERAGE_DIR}"

# parse parameters
while [[ "$#" -gt 0 ]]; do
    case $1 in
        -ts|--tsanitize) USE_THREAD_SANITIZER="ON"; shift ;;
        -as|--asanitize) USE_ADDRESS_SANITIZER="ON"; shift ;;
        -r|--release) BUILD_TYPE="Release"; shift ;;
        -c|--coverage) USE_COVERAGE="ON"; shift ;;
        -gh|--html) USE_COVERAGE_HTML="ON"; shift ;;
        -h|--help) show_help ;;
        *) echo "Unknown parameter $1"; exit 1 ;;
    esac
done

if [[ "$USE_THREAD_SANITIZER" == "ON" ]] && [[ "$USE_ADDRESS_SANITIZER" == "ON" ]]; then
    echo "Both sanitizer is ON, use address sanitize by default"
    USE_THREAD_SANITIZER="OFF"
fi

echo "-------------------------------------------------------"
echo "Build Type: $BUILD_TYPE"
echo "Thread sanitizer:  $USE_THREAD_SANITIZER"
echo "Thread sanitizer:  $USE_ADDRESS_SANITIZER"
echo "Use coverage:  $USE_COVERAGE"
echo "Generate coverage html:  $USE_COVERAGE_HTML"
echo "-------------------------------------------------------"

echo "--------------------------------Start build---------------------------" 

# clean and make build folder
remove_build_dir
mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

CXX_FLAGS=""
LDFLAGS=""

if [ "${USE_COVERAGE}" == "ON" ]; then
    CXX_FLAGS="--coverage -O0 -g"
    LDFLAGS="--coverage"
fi

cmake -DCMAKE_BUILD_TYPE="$BUILD_TYPE" \
      -DENABLE_THREAD_SANITIZER="$USE_THREAD_SANITIZER" \
      -DENABLE_ADDRESS_SANITIZER="$USE_ADDRESS_SANITIZER" \
      -DCMAKE_CXX_FLAGS="$CXX_FLAGS" \
      -DCMAKE_EXE_LINKER_FLAGS="$LDFLAGS" \
      ..

cmake --build . --parallel $(nproc)

echo "--------------------------------Build finished---------------------------" 

# run all tests
echo "--------------------------------Run tests---------------------------"
if [ "$USE_THREAD_SANITIZER" == "ON" ]; then
    find "$BUILD_DIR" -type f -name "test_*" -executable -exec setarch $(uname -m) -R {} \;
else
    find "$BUILD_DIR" -type f -name "test_*" -executable -exec {} \;
fi

if [ "$USE_COVERAGE" == "ON" ]; then

    # generate report
    echo "--------------------------------Generate coverage report---------------------------" 
    cd "${PROJECT_ROOT}"
    lcov --capture --directory "${BUILD_DIR}" --output-file "${COVERAGE_DIR}/all_data.info" --ignore-errors mismatch
    lcov --extract "${COVERAGE_DIR}/all_data.info" '*/src/*' --output-file "${COVERAGE_DIR}/src_only.info" --ignore-errors unused
    lcov --remove "${COVERAGE_DIR}/src_only.info" '*/tests/*' --output-file "${COVERAGE_DIR}/final_coverage.info" --ignore-errors unused
    if [ "$USE_COVERAGE_HTML" == "ON" ]; then
        genhtml "${COVERAGE_DIR}/final_coverage.info" --output-directory "${COVERAGE_DIR}/html" --ignore-errors mismatch

        if command -v xdg-open > /dev/null; then
            xdg-open "${COVERAGE_DIR}/html/index.html"
        elif command -v open > /dev/null; then
            open "${COVERAGE_DIR}/html/index.html"
        else
            echo "Report generated at: ${COVERAGE_DIR}/html/index.html"
        fi
    fi

fi

echo "--------------------------------Done---------------------------"

