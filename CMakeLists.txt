cmake_minimum_required(VERSION 3.20)
project(untitled C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

# Add include directories (for headers)
include_directories(${CMAKE_SOURCE_DIR}/src)

# Define the executable and add all the source files to the target
add_executable(cfeeny
        src/cfeeny.c
        src/ast.c
        src/interpreter.c
        src/utils.c
        src/lib/hashmap/hashmap.h
        src/lib/hashmap/hashmap.c
        src/lib/object/object.c
        src/lib/object/object.h
        src/lib/object/int_object.c
        src/lib/object/int_object.h
        src/lib/object/null_object.c
        src/lib/object/null_object.h
        src/lib/object/array_object.c
        src/lib/object/array_object.h
        src/lib/object/env_object/env_object.c
        src/lib/object/env_object/env_object.h
        src/lib/object/string_object.c
        src/lib/object/string_object.h
)

# Create a separate test executable
add_executable(test_hashmap
        src/lib/hashmap/test_hashmap.c
        src/ast.c
        src/ast.h
        src/interpreter.c
        src/interpreter.h
        src/utils.c
        src/utils.h
        src/lib/hashmap/hashmap.h
        src/lib/hashmap/hashmap.c
        src/lib/object/object.c
        src/lib/object/object.h
        src/lib/object/int_object.c
        src/lib/object/int_object.h
        src/lib/object/null_object.c
        src/lib/object/null_object.h
        src/lib/object/array_object.c
        src/lib/object/array_object.h
)