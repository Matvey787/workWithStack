#ifndef STACKINITDESTROY
#define STACKINITDESTROY

#include <stdio.h>
#include "macros.h"
#include "stackConstructor.h"
#include <stdarg.h>

int stackInit(stack_t* stack ON_DEBUG(, const char* fileName, const int fileLine));
int stackInit(stack_t* stack, size_t startCapacity ON_DEBUG(, const char* fileName, const int fileLine));
void stackDestroy(stack_t* stack);

#endif