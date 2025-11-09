#!/usr/bin/env bash

cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=install/ && cmake --build build && ctest --test-dir build
