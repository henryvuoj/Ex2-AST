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
        src/lib/hashmap.c  # Add the source file where print_string is defined
)
