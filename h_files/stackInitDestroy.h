#ifndef STACKINITDESTROY
#define STACKINITDESTROY

#include <stdio.h>
#include "macros.h"
#include "stackConstructor.h"
#include <stdarg.h>

int stackInit(stack_t* stack);
int stackInit(stack_t* stack, size_t startCapacity);

int stackInitDebug(stack_t* stack, const char* fileName, const int fileLine);
int stackInitDebug(stack_t* stack, size_t startCapacity, const char* fileName, const int fileLine);

void stackDestroy(stack_t* stack);

#endif