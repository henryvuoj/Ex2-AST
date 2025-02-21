//
// Created by sgvn on 20/02/2025.
//

#ifndef HASHMAP_H
#define HASHMAP_H

#include "lib/object/array_object.h"

typedef struct {
    int size;
    ArrayObj* array;
} Hashmap;

Hashmap* make_hashmap(int size);
Obj* hashmap_put(Hashmap* hashmap, Obj* key, Obj* value);
Obj* hashmap_get(Hashmap* hashmap, Obj* key);
Obj* hashmap_remove(Hashmap* hashmap, Obj* key);

#endif //HASHMAP_H
