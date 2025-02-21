//
// Created by VHHV on 21/2/25.
//

#ifndef STRING_OBJECT_H
#define STRING_OBJECT_H
#include "object.h"

typedef struct {
    ObjType type;
    char* value;
    int64_t hash_value;
} StringObj;

StringObj* make_string_obj(const char* value);

#endif //STRING_OBJECT_H
