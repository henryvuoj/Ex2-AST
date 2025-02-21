//
// Created by VHHV on 21/2/25.
//

#include "int_object.h"


IntObj* make_int_obj(int value) {
    IntObj* obj = malloc(sizeof(IntObj));
    obj->type = OBJ_INT;
    obj->value = value;
    obj->hash_value = value;
    return obj;
}
IntObj* int_add(IntObj* x, IntObj *y) {
    return make_int_obj(x->value + y->value);
}
IntObj* int_sub(IntObj* x, IntObj *y) {
    return make_int_obj(x->value - y->value);
}
IntObj* int_mul(IntObj* x, IntObj *y) {
    return make_int_obj(x->value * y->value);
}
IntObj* int_div(IntObj* x, IntObj *y) {
    return make_int_obj(x->value / y->value);
}
Obj* int_lt(IntObj* x, IntObj *y) {
    if (x->value < y->value) {
        return make_int_obj(0);
    } else {
        return make_null_obj();
    }
}
Obj* int_lte(IntObj* x, IntObj *y) {
    if (x->value <= y->value) {
        return make_int_obj(0);
    } else {
        return make_null_obj();
    }
}
Obj* int_gt(IntObj* x, IntObj *y) {
    if (x->value < y->value) {
        return make_int_obj(0);
    } else {
        return make_null_obj();
    }
}
Obj* int_gte(IntObj* x, IntObj *y) {
    if (x->value <= y->value) {
        return make_int_obj(0);
    } else {
        return make_null_obj();
    }
}
Obj* int_eql(IntObj* x, IntObj *y) {
    if (x->value == y->value) {
        return make_int_obj(0);
    } else {
        return make_null_obj();
    }
}