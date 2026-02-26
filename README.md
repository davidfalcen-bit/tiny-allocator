# tiny-allocator

A small educational implementation of `malloc`, `free`, `realloc`, and `calloc` in C.

This project demonstrates how a simple heap memory allocator can be built using `sbrk` and a linked list of memory blocks. It is intended for learning purposes and for understanding how dynamic memory management works internally.


## ⚠️ Disclaimer

This allocator is **not suitable for production use**.

It is intentionally minimal and does not provide the safety, performance, or robustness of standard library implementations.


## Features

- Custom implementations of:
  - `mymalloc`
  - `myfree`
  - `myrealloc`
  - `mycalloc`
- Singly linked list for block management
- Reuses freed memory blocks
- Simple and readable codebase
- Built using CMake


## Project Structure
.
├── mymalloc.h
├── mymalloc.c
├── main.c
└── CMakeLists.txt



## Requirements

- C compiler (GCC or Clang recommended)
- CMake 3.10 or newer
- POSIX-compatible system (Linux, BSD, macOS)


## Build

Clone the repository and build the project:

```bash
git clone https://github.com/your-username/tiny-allocator.git
cd tiny-allocator

mkdir build
cd build

cmake ..
make
