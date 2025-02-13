#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "utils.h"
#include "ast.h"
#include "interpreter.h"

void interpret (ScopeStmt* stmt) {
  printf("AST Structure:\n");
  print_tree(stmt, 0);
  printf("\nExecuting Feeny Program...\n");
  printf("Interpret program:\n");
  print_scopestmt(stmt);
  printf("\n");  
}
