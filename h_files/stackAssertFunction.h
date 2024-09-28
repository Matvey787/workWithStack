#ifndef STACKASSERTFUNCTION
#define STACKASSERTFUNCTION

#include <stdio.h>
#include "macros.h"
#include "stackConstructor.h"

void stackAssertFunc(stack_t* stack, const char* fileName, int lineNumber, const char* calledFunction);

#endif