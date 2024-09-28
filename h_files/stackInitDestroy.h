#ifndef STACKINITDESTROY
#define STACKINITDESTROY

#include <stdio.h>
#include "macros.h"
#include "stackConstructor.h"

int stackInit(stack_t* stack ON_DEBUG(, const char* fileName, int fileLine));
void stackDestroy(stack_t* stack);

#endif