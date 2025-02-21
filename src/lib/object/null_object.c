//
// Created by VHHV on 21/2/25.
//

#include "null_object.h"

Obj* make_null_obj() {
    NullObj* obj = malloc(sizeof(NullObj));
    obj->type = OBJ_NULL;
    obj->hash_value = 0;
    return (Obj*) obj;
}
