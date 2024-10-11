#ifndef STACKPUSHPOP
#define STACKPUSHPOP

#include <stdio.h>
#include "stackConstructor.h"

int stackPush(stack_t* stack, double number);
StackElem_t stackPop(stack_t* stack);

#endif