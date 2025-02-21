//
// Created by VHHV on 21/2/25.
//

#ifndef ENV_OBJECT_H
#define ENV_OBJECT_H

#include "lib/hashmap/hashmap.h"
#include "lib/object/string_object.h"

typedef struct Entry {
    char* name;
    Obj* value;
    struct Entry* next;
} Entry;

typedef struct EnvObj {
    ObjType type;
    struct EnvObj* parent;
    Hashmap* entries;
} EnvObj;

EnvObj* make_env_obj(EnvObj* parent);
Obj* add_entry(EnvObj* env, char* name, Obj* value);
Obj* get_entry(EnvObj* env, char* name);

#endif //ENV_OBJECT_H
