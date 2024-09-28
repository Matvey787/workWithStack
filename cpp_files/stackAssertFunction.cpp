#include <assert.h>

#include "../h_files/stackDump.h"
#include "../h_files/stackConstructor.h"
#include "../h_files/errorNames.h"
#include "../h_files/stackAssertFunction.h"
#include "../h_files/stackError.h"
#include "../h_files/macros.h"

void stackAssertFunc(stack_t* stack, const char* fileName, int lineNumber, const char* calledFunction){
    if (stackError(stack) == INCORRECT_STACK)
    {
        MACRO_stackDump(*stack);
        printf("something bad with stack in %s:%d in function %s\n", fileName, lineNumber, calledFunction);
        assert(0 && "stack is broken");
    }
}
