//
// Created by VHHV on 21/2/25.
//

#ifndef OBJECT_H
#define OBJECT_H

#include <stdint.h>
#include <stdlib.h>
#include <_time.h>

#include "object.h"

typedef enum {
    OBJ_NULL,
    OBJ_INT,
    OBJ_ARRAY,
    OBJ_ENV
} ObjType;
typedef struct {
    ObjType type;
    int64_t hash_value;
} Obj;

ObjType obj_type (Obj* o);

#endif //OBJECT_H
