//
// Created by VHHV on 21/2/25.
//

#include "env_object.h"

const int MAX_VALUE = 100;

EnvObj* make_env_obj(EnvObj* parent) {
    EnvObj* env = malloc(sizeof(EnvObj));
    env->type = OBJ_ENV;
    env->parent = parent;
    env->entries = make_hashmap(MAX_VALUE);
    return env;
}

Obj* add_entry(EnvObj* env, char* name, Obj* value) {
    StringObj* name_str = make_string_obj(name);
    Obj* existedEntry = hashmap_get(env->entries, name_str);
    if (existedEntry->type == OBJ_NULL) {
        hashmap_put(env->entries, name_str, value);
    }
}

Obj* get_entry(EnvObj* env, char* name) {
    return hashmap_get(env->entries, make_string_obj(name));
}