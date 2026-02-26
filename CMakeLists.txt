cmake_minimum_required(VERSION 3.10)

project(mymalloc_demo C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(mymalloc_demo
    main.c
    mymalloc.c
)
