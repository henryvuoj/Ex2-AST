//
// Created by sgvn on 20/02/2025.
//
#include "../interpreter.h"
#include "hashmap.h"

#include <stdlib.h>

int compute(Obj* obj, Hashmap* hashmap) {
    return (int)(obj->timestamp / hashmap->size);
}

Hashmap* make_hashmap(int size) {
    Hashmap* hm = malloc(sizeof(Hashmap));
    hm->size = size;
    hm->array = make_array_obj(
        make_int_obj(size),
        make_null_obj()
    );
    return hm;
}

Obj* put(Hashmap* hashmap, Obj* key, Obj* value) {
    int idx = compute(key, hashmap);
    array_set(
        hashmap->array,
        make_int_obj(idx),
        value
    );
}
