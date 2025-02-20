//
// Created by sgvn on 20/02/2025.
//

#ifndef HASHMAP_H
#define HASHMAP_H

typedef struct {
    int size;
    ArrayObj* array;
} Hashmap;

Hashmap* make_hashmap(int size);
Obj* put(Obj* key, Obj* value);
NullObj* remove(Obj* key);
Obj* contain_key(Obj* key);
Obj* contain_value(Obj* value);

#endif //HASHMAP_H
