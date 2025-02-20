//
// Created by sgvn on 20/02/2025.
//

int compute(Obj* obj, Hashmap* hashmap) {
    int map_key = obj
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

