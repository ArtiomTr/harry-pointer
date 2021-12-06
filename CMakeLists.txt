cmake_minimum_required(VERSION 3.20)
project(harry_pointer C)

set(CMAKE_C_STANDARD 99)

file(GLOB SRC_FILES *.c)
add_executable(harry_pointer ${SRC_FILES})
