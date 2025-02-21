//
// Created by VHHV on 21/2/25.
//

#ifndef ARRAY_OBJECT_H
#define ARRAY_OBJECT_H

#include "object.h"
#include "int_object.h"
#include "null_object.h"

#include <stdlib.h>
#include <time.h>


typedef struct {
    ObjType type;
    int size;         // The size of the array
    Obj** elements;   // Pointer to an array of Obj pointers (can hold different types of objects)
    int64_t hash_value;
} ArrayObj;

ArrayObj* make_array_obj (IntObj* length , Obj* init);
IntObj* array_length (ArrayObj* a);
NullObj* array_set (ArrayObj* a, IntObj* i, Obj* v);
Obj* array_get (ArrayObj* a, IntObj* i);

#endif //ARRAY_OBJECT_H
