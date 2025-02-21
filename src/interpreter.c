#include<stdio.h>
#include "ast.h"
#include "interpreter.h"

void interpret (ScopeStmt* stmt) {
  printf("Interpret program:\n");
  print_scopestmt(stmt);
  printf("\n");  
}
