//
// Created by sgvn on 20/02/2025.
//
#include "hashmap.h"

#include <stdlib.h>

int hashmap_compute(Obj* obj, Hashmap* hashmap) {
    return (int)(obj->hash_value % hashmap->size);
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

Obj* hashmap_put(Hashmap* hashmap, Obj* key, Obj* value) {
    int idx = hashmap_compute(key, hashmap);
    array_set(
        hashmap->array,
        make_int_obj(idx),
        value
    );
    return value;
}

Obj* hashmap_get(Hashmap* hashmap, Obj* key) {
    int idx = hashmap_compute(key, hashmap);
    Obj* value = array_get(hashmap->array, make_int_obj(idx));
    if (value->type == OBJ_NULL) {
        return make_null_obj();
    } else {
        array_set(hashmap->array, make_int_obj(idx), make_null_obj());
        return value;
    }
}

Obj* hashmap_remove(Hashmap* hashmap, Obj* key) {
    int idx = hashmap_compute(key, hashmap);
    Obj* value = array_get(hashmap->array, make_int_obj(idx));
    if (value->type == OBJ_NULL) {
        return make_null_obj();
    } else {
        array_set(hashmap->array, make_int_obj(idx), make_null_obj());
        return value;
    }
}