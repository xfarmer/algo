cmake_minimum_required(VERSION 3.9)

project(algo VERSION 0.0.1)

##### Compile options
add_compile_options(-g -Wall)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wl,--no-undefined")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,--no-undefined")

##### Include paths
include_directories(.)
include_directories(./src)

##### Source files
file(GLOB_RECURSE COMMON_SRC ./src/*.c ./src*.cc ./src*.cpp)

##### Setting target library name, different platforms may have different suffixes
set(TARGET_LIB_NAME farmer_algo)

##### Build library
add_library(${TARGET_LIB_NAME} STATIC ${COMMON_SRC})
target_link_libraries(${TARGET_LIB_NAME} m)

##### Some tests
# Binary tree
add_executable(binary_tree_test tests/tree/binary_tree_test.c)
target_link_libraries(binary_tree_test  ${TARGET_LIB_NAME})

# Queue
add_executable(linked_queue_test tests/queue/linked_queue_test.c)
target_link_libraries(linked_queue_test  ${TARGET_LIB_NAME})
