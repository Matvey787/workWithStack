#include "../h_files/countHash.h"
#include "../h_files/stackConstructor.h"
#include "../h_files/errorNames.h"
#include "../h_files/stackError.h"
#include "../h_files/macros.h"

errors stackError(stack_t* stack){

    if (stack == NULL) return INCORRECT_STACK_POINTER; 

    if (countHash(stack) != stack->hash) return WARNINNG_INCORRECT_HASH;

    if (stack->data == NULL) return INCORRECT_DATA_POINTER;

    if (stack->size > stack->capacity + 1) return LACK_OF_CAPACITY;

    return NO_ERROR;

}
