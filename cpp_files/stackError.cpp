#include "../h_files/macros.h"
#include "../h_files/stackConstructor.h"
#include "../h_files/errorNames.h"
#include "../h_files/stackError.h"

int stackError(stack_t* stack){

    if (stack == NULL) {printf("stack is not exist\n"); return INCORRECT_STACK; }
    if (stack->data == NULL) {printf("stack data is NULL\n"); return INCORRECT_STACK; }
    if (stack->size > stack->capacity) {printf("capasity is less then size\n"); return INCORRECT_STACK; }
    return 0;
}
