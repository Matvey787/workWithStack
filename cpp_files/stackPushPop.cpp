#include <stdio.h>
#include <stdlib.h>

#include "../h_files/countHash.h"
#include "../h_files/stackConstructor.h"
#include "../h_files/stackAssertFunction.h"
#include "../h_files/stackPushPop.h"
#include "../h_files/errorNames.h"
#include "../h_files/macros.h"

static void realloc_Data(StackElem_t** data, size_t capacity);

int stackPush(stack_t* stack, double number){
    
    MACRO_stackAssertFunction((*stack)); // TODO check stack == nullptr

#ifdef TURN_ON_CANARIES
    //               \/ for canaries
    if (stack->size + 3 > stack->capacity){
        stack->capacity = 2*(stack->capacity - 2) + 2;
        realloc_Data(&(stack->data), stack->capacity);
    }

    stack->data[++stack->size] = number;
    stack->data[stack->size + 1] = canaryConst;

    stack->hash = countHash(stack);
#else 

    if (stack->size >= stack->capacity){
        stack->capacity = 2*(stack->capacity);
        realloc_Data(&(stack->data), stack->capacity);
    }

    stack->data[stack->size++] = number;

    ON_HASH(stack->hash = countHash(stack);)

#endif
    return 0;

}

double stackPop(stack_t* stack){

    MACRO_stackAssertFunction((*stack));
    
    if (stack->size == 0){ printf("stack is empty\n"); return -666; }


#ifdef TURN_ON_CANARIES

    StackElem_t popElement = stack->data[stack->size--];

    if ((0 < stack->size) && (stack->size <= ((stack->capacity - 2) /4))){
        stack->capacity = (stack->capacity - 2) / 4 + 2;
        realloc_Data(&(stack->data), stack->capacity); 
    }

    stack->data[stack->size + 1] = canaryConst;
    ON_HASH(stack->hash = countHash(stack);)
#else

    StackElem_t popElement = stack->data[--stack->size];

    if ((0 < stack->size) && (stack->size <= (stack->capacity / 4))){
        stack->capacity = stack->capacity / 4;
        realloc_Data(&(stack->data), stack->capacity); 
    }

    ON_HASH(stack->hash = countHash(stack);)
#endif
    return popElement;

}

static void realloc_Data(StackElem_t** data, size_t capacity){
    *data = (StackElem_t*)realloc(*data, sizeof(StackElem_t)*capacity);
}
