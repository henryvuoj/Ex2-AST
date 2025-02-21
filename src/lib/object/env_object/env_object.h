//
// Created by VHHV on 21/2/25.
//

#ifndef ENV_OBJECT_H
#define ENV_OBJECT_H

#include "ast.h"
#include "lib/object/string_object.h"

// Entry (stores variables, functions, or object properties)
typedef enum { ENTRY_VAR, ENTRY_FUNC } EntryType;

typedef struct Entry {
    char* name;
    EntryType type;
    union {
        Obj* value; // Variable value
        struct {
            int nargs;
            char** args;
            ScopeStmt* body;
        } func; // Function data
    };
    struct Entry* next;
} Entry;

// Environment Object (stores variables/functions/fields)
typedef struct EnvObj {
    ObjType type;
    struct EnvObj* parent; // Parent scope
    Entry* entries; // Linked list of variables/functions
} EnvObj;

// Function Prototypes
EnvObj* make_env_obj(EnvObj* parent);
void add_entry(EnvObj* env, char* name, Obj* value, int nargs, char** args, ScopeStmt* body);
Entry* get_entry(EnvObj* env, char* name);

#endif //ENV_OBJECT_H
