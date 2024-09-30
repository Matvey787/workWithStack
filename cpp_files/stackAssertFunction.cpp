#include <assert.h>

#include "../h_files/stackDump.h"
#include "../h_files/colors.h"
#include "../h_files/stackConstructor.h"
#include "../h_files/errorNames.h"
#include "../h_files/stackAssertFunction.h"
#include "../h_files/stackError.h"
#include "../h_files/macros.h"

static const char* chooseError(errors error);

void stackAssertFunc(stack_t* stack, const char* fileName, int lineNumber, const char* calledFunction){

    errors error = NO_ERROR;

    if ((error = stackError(stack)) != NO_ERROR)
    {
        printf("Something bad with stack in %s:%d in function %s\n", fileName, lineNumber, calledFunction);
        printf("Error [%s%s%s]\n", RED, chooseError(error), EXITCOLOR);

        if (error != INCORRECT_STACK_POINTER)
            MACRO_stackDump(*stack);

        assert(0 && "stack is broken");
        
    }

}

static const char* chooseError(errors error){

    switch (error)
    {
    case INCORRECT_STACK_POINTER:
        return "INCORRECT_STACK_POINTER";
        break;

    case INCORRECT_DATA_POINTER:
        return "INCORRECT_DATA_POINTER";
        break;

    case LACK_OF_CAPACITY:
        return "LACK_OF_CAPACITY";
        break;
    
    case WARNINNG_INCORRECT_HASH:
        return "WARNINNG_INCORRECT_HASH";
        break;

    case NO_ERROR:
        return "everything ok";
        break;

    default:
        break;
    }

    return "everything ok";
    
}