#include "../h_files/stackConstructor.h"
#include "../h_files/countHash.h"

static unsigned long summBytesToHash(unsigned long important_bytes, unsigned char* bytes_pointer);

unsigned long countHash(stack_t* stack){

    ON_HASH(long unsigned remembered_hash = stack->hash; stack->hash = 0; )

    long unsigned hash = 5381;

    hash += summBytesToHash(sizeof(stack), (unsigned char*)stack);
    hash += summBytesToHash((stack->size - 1)*sizeof(StackElem_t), (unsigned char*)stack->data);

    ON_HASH(stack->hash = remembered_hash;)

    return hash;
}

static unsigned long summBytesToHash(unsigned long important_bytes, unsigned char* bytes_pointer){

    unsigned long summaryOfBytesInHash = 0;

    for (size_t readedBytes = 0; readedBytes < important_bytes; readedBytes++){
        summaryOfBytesInHash += ( ( summaryOfBytesInHash * 32 ) ^ (size_t)( *bytes_pointer++ ) );
    }

    return summaryOfBytesInHash;

}