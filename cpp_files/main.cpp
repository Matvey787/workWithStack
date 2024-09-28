#include <stdio.h>
#include <stdlib.h>

#include "../h_files/macros.h"
#include "../h_files/stackConstructor.h"
#include "../h_files/stackPushPop.h"
#include "../h_files/errorNames.h"
#include "../h_files/stackInitDestroy.h"
#include "../h_files/stackDump.h"


#define CHECK_ if (!smthGoBad) smthGoBad = 












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


