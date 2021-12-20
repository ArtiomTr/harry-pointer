file(GLOB SRC_FILES *.c)
add_executable(compiler ${SRC_FILES})

include_directories(../lib)
target_link_libraries(compiler harry_pointer)