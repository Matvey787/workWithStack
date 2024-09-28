#ifndef STACKDUMP
#define STACKDUMP

#include <stdio.h>
#include "macros.h"
#include "stackConstructor.h"

void stackDump(stack_t* stack ON_DEBUG(,const char* stackName, const char* fileName, int fileLine, const char* calledFunction));

#endif