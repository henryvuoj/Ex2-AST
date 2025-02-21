//
// Created by VHHV on 21/2/25.
//

#include "array_object.h"

ArrayObj* make_array_obj (IntObj* length , Obj* init) {
    int size = length->value;
    ArrayObj* obj = malloc(sizeof(ArrayObj));
    obj->type = OBJ_ARRAY;
    //Temporary
    obj->hash_value = 0;
    obj->size = size;
    obj->elements = malloc(sizeof(Obj*) * size);
    for (int i =0; i < size; i++) {
        obj->elements[i] = init;
    }
    return obj;
}
IntObj* array_length (ArrayObj* a) {
    return make_int_obj(a->size);
}
NullObj* array_set (ArrayObj* a, IntObj* i, Obj* v) {
    a->elements[i->value] = v;
    return make_null_obj();
}

Obj* array_get (ArrayObj* a, IntObj* i) {
    return a->elements[i->value];
}