#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../h_files/macros.h"
#include "../h_files/stackConstructor.h"
#include "../h_files/stackPushPop.h"
#include "../h_files/errorNames.h"
#include "../h_files/stackInitDestroy.h"
#include "../h_files/stackDump.h"


#define CHECK_ if (!smthGoBad) smthGoBad = 


int main(){

    stack_t stack;
    MACRO_stackInit(&stack, 10);
    
    int smthGoBad = 0;
    CHECK_ stackPush(&stack, 1.2);
    MACRO_stackDump(stack);

    CHECK_ stackPush(&stack, 3.4);
    MACRO_stackDump(stack);

    CHECK_ stackPush(&stack, 1.1);
    MACRO_stackDump(stack);

    CHECK_ stackPush(&stack, 3.5);
    MACRO_stackDump(stack);

    stackPop(&stack);
    MACRO_stackDump(stack);

    stackPop(&stack);
    MACRO_stackDump(stack);

    stackPop(&stack);
    MACRO_stackDump(stack);

    stackDestroy(&stack);
}
