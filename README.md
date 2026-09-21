# C++ Starter App

A minimal interactive C++17 console application.

## Run with the compiler

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic main.cpp -o app
./app
```

## Build with CMake

```bash
cmake -S . -B build
cmake --build build
./build/cpp_starter_app
```