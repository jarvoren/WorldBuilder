#!/bin/bash

cmake -S . build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Debug

cmake -S . -B build && cmake --build build --parallel
