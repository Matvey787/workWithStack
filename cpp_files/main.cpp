#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../h_files/colors.h"
#include "../h_files/macros.h"
#include "../h_files/stackConstructor.h"
#include "../h_files/stackPushPop.h"
#include "../h_files/errorNames.h"

#define CHECK_ if (!smthGoBad) smthGoBad = 


void stackDump(stack_t* stack ON_DEBUG(,const char* stackName, const char* fileName, int fileLine, const char* calledFunction));


int stackInit(stack_t* stack ON_DEBUG(, const char* fileName, int fileLine));
void stackDestroy(stack_t* stack);



int stackError(stack_t* stack);
void stackAssertFunc(stack_t* stack, const char* fileName, const char* lineNumber);


const int startCapasity = 1;



int main(){

    stack_t stack;
    MACRO_stackInit(stack);
    
    int smthGoBad = 0;
    CHECK_ stackPush(&stack, 1.2);
    MACRO_stackDump(stack);

/*     CHECK_ stackPush(&stack, 3.4);
    stackDump(&stack);

    CHECK_ stackPush(&stack, 1.1);
    stackDump(&stack);

    CHECK_ stackPush(&stack, 3.5);
    stackDump(&stack);

    CHECK_ stackPush(&stack, 3.5);
    stackDump(&stack);

    //x = stackPop(&stack);
    stackDump(&stack); */

    stackDestroy(&stack);
}

int stackInit(stack_t* stack ON_DEBUG(, const char* fileName, const int fileLine)){

    stack->capacity = startCapasity;
    stack->size = 0;
    stack->data = (StackElem_t*)calloc(stack->capacity, sizeof(StackElem_t));

    ON_DEBUG(stack->info.fileName_WhereStackHasBeenCreated = fileName;)
    ON_DEBUG(stack->info.line_WhereStackHasBeenCreated = fileLine;)
    ON_DEBUG(stack->info.function_WhereStackHasBeenCreated = __func__;)

    return 1;

}

void stackDump(stack_t* stack ON_DEBUG(,const char* stackName, const char* fileName, int fileLine, const char* calledFunction)){

    printf("stack_t[%p]\n", stack);

    ON_DEBUG
    (
    printf("Called from %s:%d (%s)\n", fileName, fileLine, calledFunction);
    printf("Stack %s was created in %s:%d by function %s\n", stackName, stack->info.fileName_WhereStackHasBeenCreated,
     stack->info.line_WhereStackHasBeenCreated = fileLine, stack->info.function_WhereStackHasBeenCreated);
    )

    printf("{\n");

    printf("%sStack:%s \n", WHITE_BLACKBACKGROUND, EXITCOLOR);
    printf("%scapasity:%s %lu \n%ssize:%s %lu\n", YELLOW, WHITE, stack->capacity, YELLOW, WHITE,stack->size);
    printf("data: \n");
    for (size_t i = 0; i < stack->capacity; i++)
        printf("%g \n", stack->data[i]);

    printf("}\n");
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
        //stackDump(stack);
        printf("something bad with stack in %s:%s\n", fileName, lineNumber);
        assert(0 && "stack is broken");
    }
}


