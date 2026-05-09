#!/usr/bin/env bash

if [[ -z "${ENV_SH_INCLUDED}" ]]; then
    export ENV_SH_INCLUDED=1

    SCRIPT_DIR=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)

    PROJECT_ROOT=$(cd "$SCRIPT_DIR/.." && pwd)
    export PROJECT_ROOT
    export BUILD_DIR="$PROJECT_ROOT/build"
    export COVERAGE_DIR="$PROJECT_ROOT/coverage_report"
    export TOOLS_DIR="$PROJECT_ROOT/tools"

    export RED='\033[0;31m'
    export GREEN='\033[0;32m'
    export NC='\033[0m' # No Color

    for cmd in cmake g++ lcov; do
        if ! command -v "$cmd" &> /dev/null; then
            echo -e "${RED}[ERROR] Required command '$cmd' not found!${NC}"
            exit 1
        fi
    done
fi