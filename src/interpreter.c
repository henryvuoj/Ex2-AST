#include "interpreter.h"

void interpret(ScopeStmt* stmt) {
    printf("Interpret program:\n");
    print_scopestmt(stmt);
    printf("\n");
    EnvObj* global_env = make_env_obj(NULL); // Global environment
    exec_stmt(global_env, global_env, stmt);
}

void exec_stmt(EnvObj* genv, EnvObj* env, ScopeStmt* stmt) {
    switch (stmt->tag) {
        case VAR_STMT: {
            ScopeVar* var_stmt = (ScopeVar*)stmt;
            Obj* value = eval_exp(genv, env, var_stmt->exp);
            add_entry(env, var_stmt->name, value, 0, NULL, NULL);
            break;
        }

        case FN_STMT: {
            ScopeFn* fn_stmt = (ScopeFn*)stmt;
            add_entry(env, fn_stmt->name, NULL, fn_stmt->nargs, fn_stmt->args, fn_stmt->body);
            break;
        }

        case SEQ_STMT: {
            ScopeSeq* seq_stmt = (ScopeSeq*)stmt;
            exec_stmt(genv, env, seq_stmt->a);
            exec_stmt(genv, env, seq_stmt->b);
            break;
        }

        case EXP_STMT: {
            ScopeExp* stmt_exp = (ScopeExp*)stmt;
            eval_exp(genv, env, stmt_exp->exp);
            break;
        }

        case IF_EXP: {
            IfExp* if_stmt = (IfExp*)stmt;
            Obj* cond = eval_exp(genv, env, if_stmt->pred);
            if (((IntObj*)cond)->value) {
                exec_stmt(genv, env, if_stmt->conseq);
            } else {
                exec_stmt(genv, env, if_stmt->alt);
            }
            break;
        }

        case WHILE_EXP: {
            WhileExp* while_stmt = (WhileExp*)stmt;
            while (((IntObj*)eval_exp(genv, env, while_stmt->pred))->value) {
                exec_stmt(genv, env, while_stmt->body);
            }
            break;
        }

        default:
            printf("Error: Unknown statement type %d\n", stmt->tag);
            exit(-1);
    }
}

Obj* eval_stmt(EnvObj* genv, EnvObj* env, ScopeStmt* stmt) {
    switch (stmt->tag) {
        case EXP_STMT: {
            ScopeExp* stmt_exp = (ScopeExp*)stmt;
            return eval_exp(genv, env, stmt_exp->exp);
        }
        case SEQ_STMT:{
            ScopeSeq* s2 = (ScopeSeq*)stmt;
            exec_stmt(genv, env, s2->a);
            exec_stmt(genv, env, s2->b);
            break;
        }
        default:
            printf("Error: Unknown statement type %d\n", stmt->tag);
        exit(-1);
    }
}

Obj* eval_exp(EnvObj* genv, EnvObj* env, Exp* exp) {
    switch (exp->tag) {
        case INT_EXP: {
            IntExp* int_exp = (IntExp*)exp;
            return (Obj*)make_int_obj(int_exp->value);
        }

        case NULL_EXP: {
            return make_null_obj();
        }

        case REF_EXP: {
            RefExp* ref_exp = (RefExp*)exp;
            Entry* entry = get_entry(env, ref_exp->name);
            if (entry == NULL) {
                printf("Error: Variable '%s' not found.\n", ref_exp->name);
                exit(-1);
            }
            return entry->value;
        }

        case CALL_EXP: {
            CallExp* call_exp = (CallExp*)exp;
            Entry* entry = get_entry(env, call_exp->name);
            if (entry->type != ENTRY_FUNC) {
                printf("Error: '%s' is not a function.\n", call_exp->name);
                exit(-1);
            }

            EnvObj* func_env = make_env_obj(env);

            for (int i = 0; i < entry->func.nargs; i++) {
                Obj* arg_value = eval_exp(genv, env, call_exp->args[i]);
                add_entry(func_env, entry->func.args[i], arg_value, 0, NULL, NULL);
            }

            return eval_stmt(genv, func_env, entry->func.body);
        }

        case CALL_SLOT_EXP: {
            CallSlotExp* call_slot_exp = (CallSlotExp*)exp;
            Obj* obj = eval_exp(genv, env, call_slot_exp->exp);
            if (obj->type != OBJ_ENV) {
                printf("Error: Cannot call method '%s' on a non-object.\n", call_slot_exp->name);
                exit(-1);
            }

            Entry* method_entry = get_entry((EnvObj*)obj, call_slot_exp->name);
            if (method_entry->type != ENTRY_FUNC) {
                printf("Error: '%s' is not a method.\n", call_slot_exp->name);
                exit(-1);
            }

            EnvObj* method_env = make_env_obj((EnvObj*)obj);
            add_entry(method_env, "this", obj, 0, NULL, NULL);

            for (int i = 0; i < method_entry->func.nargs; i++) {
                Obj* arg_value = eval_exp(genv, env, call_slot_exp->args[i]);
                add_entry(method_env, method_entry->func.args[i], arg_value, 0, NULL, NULL);
            }

            return eval_stmt(genv, method_env, method_entry->func.body);
        }

        case PRINTF_EXP: {
            PrintfExp* printf_exp = (PrintfExp*)exp;
            printf(printf_exp->format);
            break;
        }

        default:
            printf("Error: Unknown expression type %d\n", exp->tag);
            exit(-1);
    }
}
