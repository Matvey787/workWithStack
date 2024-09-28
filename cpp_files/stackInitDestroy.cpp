#include <stdio.h>
#include <stdlib.h>

#include "../h_files/stackConstructor.h"
#include "../h_files/stackInitDestroy.h"

const int startCapacity = 1;

int stackInit(stack_t* stack ON_DEBUG(, const char* fileName, const int fileLine)){

    stack->capacity = startCapacity;
    stack->size = 0;
    stack->data = (StackElem_t*)calloc(stack->capacity, sizeof(StackElem_t));

    ON_DEBUG(stack->info.fileName_WhereStackHasBeenCreated = fileName;)
    ON_DEBUG(stack->info.line_WhereStackHasBeenCreated = fileLine;)
    ON_DEBUG(stack->info.function_WhereStackHasBeenCreated = __func__;)

    return 1;

}

void stackDestroy(stack_t* stack){

    // check if with stack is all ok
    //stackError(stack);

    free(stack->data);
}