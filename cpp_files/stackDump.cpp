#include <stdio.h>

#include "../h_files/colors.h"
#include "../h_files/macros.h"
#include "../h_files/stackConstructor.h"
#include "../h_files/stackDump.h"

void stackDump(stack_t* stack ON_DEBUG(,const char* stackName, const char* fileName, int fileLine, const char* calledFunction)){

    printf("stack_t[%p]\n", stack);

    ON_DEBUG
    (
    printf("Called from %s:%d (%s)\n", fileName, fileLine, calledFunction);
    printf("Stack [%s] was created in %s:%d by function %s\n", stackName, stack->info.fileName_WhereStackHasBeenCreated,
     stack->info.line_WhereStackHasBeenCreated = fileLine, stack->info.function_WhereStackHasBeenCreated);
    )

    printf("{\n");

    printf("%sStack:%s \n", WHITE_BLACKBACKGROUND, EXITCOLOR);
    printf("%scapasity:%s %lu \n%ssize:%s %lu %sHash:%s %x\n", YELLOW, WHITE, stack->capacity, YELLOW, WHITE, stack->size, YELLOW, WHITE, stack->hash);
    printf("data: \n");
    for (size_t i = 0; i < stack->capacity; i++)
        printf("%g \n", stack->data[i]);

    printf("}\n");
}