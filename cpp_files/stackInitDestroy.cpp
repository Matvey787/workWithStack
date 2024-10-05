#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "../h_files/countHash.h"
#include "../h_files/stackAssertFunction.h"
#include "../h_files/stackConstructor.h"
#include "../h_files/stackInitDestroy.h"
#include "../h_files/macros.h"

static const int c_startCapacity = 1;

int stackInitDebug(stack_t* stack, const char* fileName, const int fileLine) {

    ON_DEBUG(stack->info.fileName_WhereStackHasBeenCreated = fileName;)
    ON_DEBUG(stack->info.line_WhereStackHasBeenCreated = fileLine;)
    ON_DEBUG(stack->info.function_WhereStackHasBeenCreated = __func__;)


    return stackInit(stack);
}

int stackInit(stack_t* stack){ // FIXME copypaste

#ifdef TURN_ON_CANARIES
    stack->capacity = c_startCapacity+2;
    stack->data = (StackElem_t*)calloc((stack->capacity), sizeof(StackElem_t)); // FIXME check
    stack->data[0] = canaryConst;
    stack->data[stack->capacity-1] = canaryConst;
#else
    stack->capacity = c_startCapacity;
    stack->data = (StackElem_t*)calloc((stack->capacity), sizeof(StackElem_t));
#endif

    stack->size = 0;
    ON_HASH(stack->hash = countHash(stack);)
    return 1;

}


int stackInitDebug(stack_t* stack, size_t user_startCapacity, const char* fileName, const int fileLine) {

    ON_DEBUG(stack->info.fileName_WhereStackHasBeenCreated = fileName;)
    ON_DEBUG(stack->info.line_WhereStackHasBeenCreated = fileLine;)
    ON_DEBUG(stack->info.function_WhereStackHasBeenCreated = __func__;)


    return stackInit(stack, user_startCapacity);
}

int stackInit(stack_t* stack, size_t user_startCapacity){ // TODO

#ifdef TURN_ON_CANARIES
    stack->capacity = user_startCapacity+2;
    stack->data = (StackElem_t*)calloc((stack->capacity), sizeof(StackElem_t));
    stack->data[0] = canaryConst;
    stack->data[stack->capacity-1] = canaryConst;
#else
    stack->capacity = user_startCapacity;
    stack->data = (StackElem_t*)calloc((stack->capacity), sizeof(StackElem_t));
#endif

    stack->size = 0;
    ON_HASH(stack->hash = countHash(stack);)

    return 1;

}

void stackDestroy(stack_t* stack){

    MACRO_stackAssertFunction((*stack));

    free(stack->data); stack->data = nullptr;

    stack->capacity = 0;
    ON_HASH(stack->hash = 0;)
    stack->size = 0;
}