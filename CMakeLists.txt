cmake_minimum_required(VERSION 3.20)
project(harry_pointer C)

set(CMAKE_C_STANDARD 99)
add_subdirectory(lib)
add_subdirectory(compiler)

file(GLOB SRC_FILES src/*.c)
add_executable(shop ${SRC_FILES})
include_directories(lib)
target_link_libraries(shop harry_pointer)
