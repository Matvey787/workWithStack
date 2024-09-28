#include <assert.h>

#include "../h_files/macros.h"
#include "../h_files/stackConstructor.h"
#include "../h_files/errorNames.h"
#include "../h_files/stackAssertFunction.h"
#include "../h_files/stackError.h"

void stackAssertFunc(stack_t* stack, const char* fileName, const char* lineNumber){
    if (stackError(stack) == INCORRECT_STACK)
    {
        //stackDump(stack);
        printf("something bad with stack in %s:%s\n", fileName, lineNumber);
        assert(0 && "stack is broken");
    }
}
