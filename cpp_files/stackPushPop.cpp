#include <stdio.h>
#include <stdlib.h>

#include "../h_files/stackConstructor.h"
#include "../h_files/stackPushPop.h"
#include "../h_files/errorNames.h"

static void reallocData(StackElem_t** data, size_t capacity);

int stackPush(stack_t* stack, double number){


    
    if (stack->size > stack->capacity){
        stack->capacity *= 2;
        reallocData(&(stack->data), stack->capacity);
    }

    stack->data[stack->size++] = number;

    return 0;
}

double stackPop(stack_t* stack){

    //stackAssertFunc(stack, "main.cpp", "78");

    if (stack->size == 0){ printf("stack is empty\n"); return INCORRECT_STACK; }

    --stack->size;

    if (1 < stack->size && stack->size <= (stack->capacity/4)) stack->data = (StackElem_t*)realloc(stack->data, sizeof(StackElem_t)*stack->size); 


    return stack->data[stack->size];
}

void reallocData(StackElem_t** data, size_t capacity){
    *data = (StackElem_t*)realloc(*data, sizeof(StackElem_t)*capacity);
}