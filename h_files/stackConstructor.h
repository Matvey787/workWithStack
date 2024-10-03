#ifndef STACKCONSTRUCTOR
#define STACKCONSTRUCTOR

#include <stdint.h>
#include <stdio.h>
#include "macros.h"

const int64_t canaryConst = 0xDED;

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
    
    ON_HASH(unsigned long hash;)
    ON_DEBUG(infoOfStack info;)
};

#endif