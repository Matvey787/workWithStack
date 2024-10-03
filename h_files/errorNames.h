#ifndef ERRORNAMES
#define ERRORNAMES

enum errors{
    NO_ERROR = 0,
    INCORRECT_STACK_POINTER = 1,
    INCORRECT_DATA_POINTER = 2,
    LACK_OF_CAPACITY = 4,
    WARNINNG_INCORRECT_HASH = 8,
    WARNINNG_BROKEN_CANARY = 16
};

#endif