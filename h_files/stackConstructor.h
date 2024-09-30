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
    size_t size;
    size_t capacity;
    StackElem_t* data;
    
    unsigned long hash;
    ON_DEBUG(infoOfStack info;)
};

#endif