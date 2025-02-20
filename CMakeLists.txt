cmake_minimum_required(VERSION 3.20)
project(untitled C)

set(CMAKE_C_STANDARD 11)

# Add include directories (for headers)
include_directories(${CMAKE_SOURCE_DIR}/src)

# Define the executable and add all the source files to the target
add_executable(cfeeny
        src/cfeeny.c
        src/ast.c
        src/interpreter.c
        src/utils.c
        src/lib/hashmap.h
        src/lib/hashmap.c
)

# Create a separate test executable
add_executable(test_hashmap
        src/lib/test_hashmap.c
        src/ast.c
        src/ast.h
        src/interpreter.c
        src/interpreter.h
        src/utils.c
        src/utils.h
        src/lib/hashmap.h
        src/lib/hashmap.c
)