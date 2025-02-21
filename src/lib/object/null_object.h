//
// Created by VHHV on 21/2/25.
//

#ifndef NULL_OBJECT_H
#define NULL_OBJECT_H
#include "object.h"
#include <stdlib.h>
#include <time.h>

typedef struct {
    ObjType type;
    int value;
    int64_t hash_value;
} NullObj;

Obj* make_null_obj();

#endif //NULL_OBJECT_H
