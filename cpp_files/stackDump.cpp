#include <stdio.h>

#include "../h_files/colors.h"
#include "../h_files/macros.h"
#include "../h_files/stackConstructor.h"
#include "../h_files/stackDump.h"

void stackDumpDebug(stack_t* stack ON_DEBUG(,const char* stackName, const char* fileName, int fileLine, const char* calledFunction)){
    
    printf("stack_t[%p]\n", stack);
    ON_DEBUG
    (
    printf("Called from %s:%d (%s)\n", fileName, fileLine, calledFunction);
    printf("Stack [%s] was created in %s:%d by function %s\n", stackName, stack->info.fileName_WhereStackHasBeenCreated,
    stack->info.line_WhereStackHasBeenCreated = fileLine, stack->info.function_WhereStackHasBeenCreated);
    )

    stackDump(stack);

}

void stackDump(stack_t* stack){

    #ifndef DEBUG 
    printf("stack_t[%p]\n", stack);
    #endif

    printf("%sStack:%s \n", WHITE_BLACKBACKGROUND, EXITCOLOR);
    printf("%scapasity:%s %lu \n%ssize:%s %lu", YELLOW, WHITE, stack->capacity, YELLOW, WHITE, stack->size);
    ON_HASH(printf(" %sHash:%s %x", YELLOW, WHITE, (unsigned int)stack->hash));

    printf("\ndata{\n");
    for (size_t i = 0; i < stack->capacity; i++){

        printf("    stack[%lu] = ", i);

        #ifdef TURN_ON_CANARIES
            (i == 0 || i == stack->size+1) ? ((i == 0) ? printf("Left canary: %x \n", (unsigned)stack->data[i]) :
            printf("Right canary: %x \n", (unsigned)stack->data[i])) :
            printf("%g \n", stack->data[i]);
        #else
            printf("%g \n", stack->data[i]);
        #endif
    }
    printf("}\n");
}