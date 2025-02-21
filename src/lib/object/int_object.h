//
// Created by VHHV on 21/2/25.
//

#ifndef INT_OBJECT_H
#define INT_OBJECT_H
#include <stdint.h>
#include "object.h"
#include "null_object.h"
#include <stdlib.h>
#include <time.h>
typedef struct {
    ObjType type;
    int value;
    int64_t hash_value;
} IntObj;

IntObj* make_int_obj(int value);
IntObj* int_add(IntObj* x, IntObj *y);
IntObj* int_sub(IntObj* x, IntObj *y);
IntObj* int_mul(IntObj* x, IntObj *y);
IntObj* int_div(IntObj* x, IntObj *y);
Obj* int_lt(IntObj* x, IntObj *y);
Obj* int_lte(IntObj* x, IntObj *y);
Obj* int_gt(IntObj* x, IntObj *y);
Obj* int_gte(IntObj* x, IntObj *y);
Obj* int_eql(IntObj* x, IntObj *y);

#endif //INT_OBJECT_H
