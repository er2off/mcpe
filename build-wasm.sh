#!/usr/bin/env bash

set -e

# Working Directory
mkdir -p wasm
cd wasm

# Clone Emscripten SDK
if [ ! -d emsdk ]; then
    git clone https://github.com/emscripten-core/emsdk.git
fi
cd emsdk

# Update Emscripten SDK
git pull
./emsdk install latest
./emsdk activate latest > /dev/null

# Use Emscripten SDK
export EMSDK_QUIET=1
source ./emsdk_env.sh

# Create Output Directory
cd ../
rm -rf dist
mkdir dist

# Configure Build
emcmake cmake -GNinja -S.. -Bbuild "$@"

# Build
cmake --build build
