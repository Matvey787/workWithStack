#include "../h_files/stackConstructor.h"
#include "../h_files/countHash.h"
unsigned long countHash(stack_t* stack){

    long unsigned hash = 0;
    unsigned long important_bytes = sizeof(stack->size) + sizeof(stack->capacity) + sizeof(stack->data);
    char* byte_ptr = (char*)stack;

    for (size_t readedBytes = 0; readedBytes < important_bytes; readedBytes++){
        hash += ((hash*31) ^ (size_t)*(byte_ptr++));
    }

    byte_ptr = (char*)stack->data;
    for (size_t readedBytes = 0; readedBytes < stack->size; readedBytes++){
        hash += ((hash*31) ^ (size_t)*(byte_ptr++));
    }
    

    return hash;
}