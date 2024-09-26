#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../h_files/colors.h"

#define CHECK_ if (!smthGoBad) smthGoBad = 

typedef double StackElem_t;

struct stack_t{
    StackElem_t* data;
    size_t size;
    size_t capacity;
};

int stackPush(stack_t* stack, double number);
void stackDump(stack_t* stack);
double stackPop(stack_t* stack);
void stackDestroy(stack_t* stack);
int stackError(stack_t* stack);
int stackInit(stack_t* stack);
void stackAssertFunc(stack_t* stack, const char* fileName, const char* lineNumber);
void reallocData(StackElem_t** data, size_t capacity);

const int startCapasity = 1;

enum errors{
    INCORRECT_STACK = 404
};

int main(){
    double x, y, z;
    stack_t stack;
    stackInit(&stack);
    z = stackPop(&stack);
    
    int smthGoBad = 0;
    CHECK_ stackPush(&stack, 1.2);
    stackDump(&stack);
    y = stackPop(&stack);
    CHECK_ stackPush(&stack, 3.4);
    stackDump(&stack);
    CHECK_ stackPush(&stack, 1.1);
    stackDump(&stack);
    CHECK_ stackPush(&stack, 3.5);
    stackDump(&stack);
    CHECK_ stackPush(&stack, 3.5);
    stackDump(&stack);

    x = stackPop(&stack);
    printf("%g %g %g\n", x, y, z);
    stackDump(&stack);
}

int stackInit(stack_t* stack){
    stack->capacity = startCapasity;
    stack->size = 0;
    stack->data = (StackElem_t*)calloc(stack->capacity, sizeof(StackElem_t));

    stackAssertFunc(stack, "main.cpp", "48");

    return 1;
}

int stackPush(stack_t* stack, double number){
    //printf("%lu\n", stack->size);
    if (stack->size + 1 > stack->capacity){
        stack->capacity *= 2;
        reallocData(&(stack->data), stack->capacity);
    }
    /* printf("%lu %lu\n", stack->capacity, stack->size); */

    if (stackError(stack) == INCORRECT_STACK) return 1;

    stack->data[stack->size++] = number;
    return 0;
}

double stackPop(stack_t* stack){

    stackAssertFunc(stack, "main.cpp", "78");

    if (stack->size == 0){ printf("stack is empty\n"); return INCORRECT_STACK; }

    --stack->size;

    if (1 < stack->size && stack->size <= (stack->capacity/4)) stack->data = (StackElem_t*)realloc(stack->data, sizeof(StackElem_t)*stack->size); 


    return stack->data[stack->size];
}

void stackDump(stack_t* stack){

    if (stack->data == NULL) {printf("data in stack is null\n"); return; }

    printf("%sStack:%s \n", WHITE_BLACKBACKGROUND, EXITCOLOR);
    printf("%scapasity:%s %lu \n%ssize:%s %lu\n", YELLOW, WHITE, stack->capacity, YELLOW, WHITE,stack->size);
    printf("data: ");

    for (size_t i = 0; i < stack->capacity; i++)
        printf("%g  ", stack->data[i]);

    printf("\n");
    printf("--------------------------------\n");
}

void stackDestroy(stack_t* stack){

    // check if with stack is all ok
    stackError(stack);

    free(stack->data);
}

int stackError(stack_t* stack){

    if (stack == NULL) {printf("stack is not exist\n"); return INCORRECT_STACK; }
    if (stack->data == NULL) {printf("stack data is NULL\n"); return INCORRECT_STACK; }
    if (stack->size > stack->capacity) {printf("capasity is less then size\n"); return INCORRECT_STACK; }
    return 0;
}

void stackAssertFunc(stack_t* stack, const char* fileName, const char* lineNumber){
    if (stackError(stack) == INCORRECT_STACK)
    {
        stackDump(stack);
        printf("something bad with stack in %s:%s\n", fileName, lineNumber);
        assert(0 && "stack is broken");
    }
}

void reallocData(StackElem_t** data, size_t capacity){
    *data = (StackElem_t*)realloc(*data, sizeof(StackElem_t)*capacity);
    if (*data == NULL)
}
