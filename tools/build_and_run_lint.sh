#!/usr/bin/env bash

set -e

# shellcheck source=/dev/null
source "$(dirname "${BASH_SOURCE[0]}")/env.sh"

# This variables uses by build_project function.
# Do no change the names!
USE_THREAD_SANITIZER="OFF"
USE_ADDRESS_SANITIZER="OFF"
USE_COVERAGE="OFF"
USE_COVERAGE_HTML="OFF"
BUILD_TYPE="Debug"
CLEAN_BUILD="OFF"

# shellcheck source=/dev/null
source "$SCRIPT_DIR/build.sh"
build_project

echo "Formatting code..."
find "$SOURCE_DIR" -path "$BUILD_DIR" -prune -o -type f \( -name "*.cpp" -o -name "*.hpp" -o -name "*.h" \) -print0 | xargs -0 clang-format -i

echo "Running static analysis..."


# -j "$(nproc)" \ use it if you have powerful CPU
find "$SOURCE_DIR" -path "$BUILD_DIR" -prune -o -type f -name "*.cpp" -print0 | xargs -0 -r run-clang-tidy \
    -p "$BUILD_DIR" \
    -header-filter="^${SOURCE_DIR}/(src|include)/.*" \
    -extra-arg="-isystem${BUILD_DIR}/_deps" | grep -v "googletest"


