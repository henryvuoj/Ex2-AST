//
// Created by VHHV on 21/2/25.
//

#include "string_object.h"

int64_t compute_hash_value(char* str) {
    int64_t hash = 5381;  // Starting value
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;  // hash = hash * 33 + c
    }

    return hash;  // Final hash value
}

StringObj* make_string_obj(char* value) {
    StringObj* obj = malloc(sizeof(StringObj));
    obj->type = OBJ_STRING;
    obj->value = value;
    obj->hash_value = compute_hash_value(value);
    return obj;
}
