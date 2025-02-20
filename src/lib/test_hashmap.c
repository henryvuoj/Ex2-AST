//
// Created by VHHV on 20/2/25.
//
#include <interpreter.h>
#include <stdio.h>
#include "hashmap.h"

int main() {
    Hashmap* map = make_hashmap(100); // Assuming a function that initializes a hashmap

    Obj* key = make_int_obj(42);  // Assuming you have a function to create integer objects
    Obj* value = make_int_obj(100);

    hashmap_put(map, key, value);

    Obj* retrieved = hashmap_get(map, key);
    if (retrieved && retrieved->type != OBJ_NULL) {
        printf("Retrieved value\n");
    } else {
        printf("Key not found\n");
    }

    return 0;
}
