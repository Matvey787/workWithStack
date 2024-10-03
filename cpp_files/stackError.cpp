#include "../h_files/countHash.h"
#include "../h_files/stackConstructor.h"
#include "../h_files/errorNames.h"
#include "../h_files/stackError.h"
#include "../h_files/macros.h"

errors stackError(stack_t* stack){

    if (stack == NULL) return INCORRECT_STACK_POINTER; 

    if (stack->data == NULL) return INCORRECT_DATA_POINTER;

    if (stack->size > stack->capacity + 1) return LACK_OF_CAPACITY;

#ifdef TURN_ON_CANARIES
    if ((((int64_t)stack->data[0] != 0xDED) || ((int64_t)stack->data[stack->size + 1] != 0xDED)) && (stack->size > 0)) return WARNINNG_BROKEN_CANARY;
#endif

    ON_HASH(if (countHash(stack) != stack->hash) return WARNINNG_INCORRECT_HASH;)

    return NO_ERROR;

}
