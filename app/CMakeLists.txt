file(GLOB SRC_FILES *.c)
add_executable(shop ${SRC_FILES})

include_directories(../lib)
target_link_libraries(shop harry_pointer)