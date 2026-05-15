#!/bin/bash

set -e

# Include environment variables.
# shellcheck source=/dev/null
source "$(dirname "${BASH_SOURCE[0]}")/env.sh"

show_help() {
    echo "Usage: ./update_submodules.sh [options]"
    echo ""
    echo "Options:"
    echo "  -t, --tag         Specify tag"
    echo "  -h, --help        Show this help message"
    echo ""
    echo "Example: ./update_submodules.sh -t v.0.1.0"
    exit 0
}

while [[ "$#" -gt 0 ]]; do
    case $1 in
        -t|--tag)
            if [[ -n "$2" && "$2" != -* ]]; then
                LATEST_TAG="$2"
                shift 2
            else
                echo "Wrong value: please specify the tag, --tag v.0.1.0)"
                exit 1
            fi
            ;;
        -h|--help) show_help ;;
        *) echo "Unknown parameter $1"; exit 1 ;;
    esac
done

git submodule update --init --recursive

cd "${API_CONTRACTS_DIR}"

git fetch --tags --all

if [ "${LATEST_TAG}" == "" ]; then
    LATEST_TAG=$(git describe --tags "$(git rev-list --tags --max-count=1)")
fi

echo "Use tag is: $LATEST_TAG"

git checkout "$LATEST_TAG"

cd "${PROJECT_ROOT}"

git status