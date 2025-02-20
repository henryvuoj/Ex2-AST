#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "ast.h"
#include <stdint.h>

typedef enum {
    OBJ_NULL,
    OBJ_INT,
    OBJ_ARRAY,
    OBJ_ENV
} ObjType;
typedef struct {
    ObjType type;
    int64_t timestamp;
} Obj;
typedef struct {
    ObjType type;
    int value;
    int64_t timestamp;
} IntObj;
typedef struct {
    ObjType type;
    int value;
    int64_t timestamp;
} NullObj;
typedef struct {
    ObjType type;
    int size;         // The size of the array
    Obj** elements;   // Pointer to an array of Obj pointers (can hold different types of objects)
    int64_t timestamp;
} ArrayObj;


void interpret (ScopeStmt* stmt);

//Normal object
ObjType obj_type (Obj* o);
//Normal object

//Null object
Obj* make_null_obj();
//Null object

//Int object
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
//Int object

//Array object
ArrayObj* make_array_obj (IntObj* length , Obj* init);
IntObj* array_length (ArrayObj* a);
NullObj* array_set (ArrayObj* a, IntObj* i, Obj* v);
Obj* array_get (ArrayObj* a, IntObj* i);
//Array object

//Env Object
//Env Object

#endif
