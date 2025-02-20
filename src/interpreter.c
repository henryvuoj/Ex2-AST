#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "utils.h"
#include "ast.h"
#include "interpreter.h"
#include <time.h>

//Normal object
ObjType obj_type (Obj* o) {
  return o->type;
}
//Normal object

//Null object
Obj* make_null_obj() {
  NullObj* obj = malloc(sizeof(NullObj));
  obj->type = OBJ_NULL;
  obj->timestamp = (int64_t)time(NULL);
  return (Obj*) obj;
}
//Null object

//Int object
IntObj* make_int_obj(int value) {
  IntObj* obj = malloc(sizeof(IntObj));
  obj->type = OBJ_INT;
  obj->value = value;
  obj->timestamp = (int64_t)time(NULL);
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
//Int object

//Array object
ArrayObj* make_array_obj (IntObj* length , Obj* init) {
  int size = length->value;
  ArrayObj* obj = malloc(sizeof(ArrayObj));
  obj->type = OBJ_ARRAY;
  obj->timestamp = (int64_t)time(NULL);
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
//Array object

//Env Object
//Env Object

void interpret (ScopeStmt* stmt) {
  printf("Interpret program:\n");
  print_scopestmt(stmt);
  printf("\n");  
}
