#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include "../h_files/countHash.h"
#include "../h_files/stackConstructor.h"
#include "../h_files/stackAssertFunction.h"
#include "../h_files/stackPushPop.h"
#include "../h_files/errorNames.h"
#include "../h_files/macros.h"

static void realloc_Data(StackElem_t** data, size_t capacity);

int stackPush(stack_t* stack, double number){
    
    if (stack == nullptr) {
        printf("NULL pointer was passed"); 
        return 1;
    }

    MACRO_stackAssertFunction((*stack));

#ifdef TURN_ON_CANARIES
    //               \/ for canaries
    if (stack->size + 2 >= stack->capacity){
        stack->capacity = 2*(stack->capacity - 2) + 2;
        realloc_Data(&(stack->data), stack->capacity);
    }

    stack->data[++stack->size] = number;
    stack->data[stack->size + 1] = canaryConst;
#else 

    if (stack->size >= stack->capacity){
        stack->capacity = 2*(stack->capacity);
        realloc_Data(&(stack->data), stack->capacity);
    }

    stack->data[stack->size++] = number;
#endif

    ON_HASH(stack->hash = countHash(stack);)
    return 0;

}

StackElem_t stackPop(stack_t* stack){

    MACRO_stackAssertFunction((*stack));
    
    if (stack->size == 0){ printf("stack is empty\n"); return NAN; }


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

    if (*data == NULL) fprintf(stderr, "can't realloc data   :(\n");
    assert(*data != NULL && "can't realloc data   :(\n");

}
