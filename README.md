# Architecture128

High-performance 128-bit integer implementation in C++ using x86-64 Assembly for core arithmetic operations.

## Features

- Custom 128-bit integer (`Int128`) implemented using two `uint64_t` values
- Arithmetic operations implemented in Assembly:
  - addition
  - subtraction
  - multiplication
- Bitwise operations:
  - AND
  - OR
  - XOR
- Full C++ operator overloading for intuitive usage

## Architecture

- C++ handles high-level logic and operator overloading
- NASM (x86-64) handles low-level arithmetic operations
- CMake manages the build system and linking

### Requirements

- CMake >= 3.20
- NASM
- C++17 compatible compiler

> NASM's path needs to be specified in  `CMakeLists.txt`

### Build steps

```bash
mkdir build
cd build
cmake ..
cmake --build .
```
