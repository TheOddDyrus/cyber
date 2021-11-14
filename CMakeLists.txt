cmake_minimum_required(VERSION 3.20)
project(cyber C)

set(CMAKE_C_STANDARD 99)

add_executable(letsgo letsgo.c)
add_executable(str punk/str.c)
add_executable(point punk/point.c)
add_executable(macros punk/macros.c)
add_executable(memory punk/memory.c)
