//
// Created by VHHV on 21/2/25.
//

#include "env_object.h"

#include <stdio.h>
#include <string.h>

EnvObj* make_env_obj(EnvObj* parent) {
    EnvObj* env = malloc(sizeof(EnvObj));
    env->type = OBJ_ENV;
    env->parent = parent;
    env->entries = NULL;
    return env;
}

void add_entry(EnvObj* env, char* name, Obj* value, int nargs, char** args, ScopeStmt* body) {
    Entry* new_entry = malloc(sizeof(Entry));
    new_entry->name = strdup(name);

    if (body == NULL) { // It's a variable
        new_entry->type = ENTRY_VAR;
        new_entry->value = value;
    } else { // It's a function
        new_entry->type = ENTRY_FUNC;
        new_entry->func.nargs = nargs;
        new_entry->func.args = args;
        new_entry->func.body = body;
    }

    // Add to the front of the linked list
    new_entry->next = env->entries;
    env->entries = new_entry;
}

Entry* get_entry(EnvObj* env, char* name) {
    for (Entry* entry = env->entries; entry != NULL; entry = entry->next) {
        if (strcmp(entry->name, name) == 0) {
            return entry;
        }
    }
    if (env->parent != NULL) {
        return get_entry(env->parent, name); // Search parent scope
    }
    printf("Error: Variable or function '%s' not found.\n", name);
    exit(-1);
}
