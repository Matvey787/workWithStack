#ifndef STACKCONSTRUCTOR
#define STACKCONSTRUCTOR

#include <stdio.h>
#include "macros.h"

typedef double StackElem_t;

struct infoOfStack{
    const char* fileName_WhereStackHasBeenCreated;
    int line_WhereStackHasBeenCreated;
    const char* function_WhereStackHasBeenCreated;
};

struct stack_t{
    ON_DEBUG(infoOfStack info;)
    StackElem_t* data;
    size_t size;
    size_t capacity;
};

#endif