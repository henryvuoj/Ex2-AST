#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "ast.h"
#include "lib/object/env_object/env_object.h"
#include <stdio.h>
#include "lib/object/int_object.h"

void interpret (ScopeStmt* stmt);
Obj* eval_exp(EnvObj* genv, EnvObj* env, Exp* exp);
void exec_stmt(EnvObj* genv, EnvObj* env, ScopeStmt* stmt);
Obj* eval_stmt(EnvObj* genv, EnvObj* env, ScopeStmt* stmt);

#endif
