//
// Created by VHHV on 20/2/25.
//
#include <interpreter.h>
#include <stdio.h>
#include "hashmap.h"

void print_check(Hashmap* map, int value) {
    Obj* retrieved = hashmap_get(map, make_int_obj(value));
    if (retrieved && retrieved->type != OBJ_NULL) {
        printf("Retrieved value: %d\n", ((IntObj*) retrieved)->value);
    } else {
        printf("Key not found\n");
    }

}

int main() {
    Hashmap* map = make_hashmap(100); // Assuming a function that initializes a hashmap

    hashmap_put(map, make_int_obj(1), make_int_obj(1001));
    print_check(map, 1);
    hashmap_put(map, make_int_obj(2), make_int_obj(1002));
    print_check(map, 2);
    hashmap_put(map, make_int_obj(3), make_int_obj(1003));
    print_check(map, 3);
    hashmap_put(map, make_int_obj(3), make_int_obj(1033));
    print_check(map, 3);
    hashmap_put(map, make_int_obj(4), make_int_obj(1004));
    print_check(map, 4);
    hashmap_remove(map, make_int_obj(3));
    print_check(map, 3);
    return 0;
}
