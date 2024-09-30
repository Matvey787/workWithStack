#include "stdint.h"
#include "../h_files/stressTests.h"
#include "../h_files/stackConstructor.h"
#include "../h_files/stackInitDestroy.h"
#include "../h_files/stackPushPop.h"
#include "../h_files/stackDump.h"
#include "../h_files/macros.h"

#define CHECK_ if (!smthGoBad) smthGoBad = 

struct tortureChamber_t{
    uint64_t leftExecutioner[1];
    stack_t stack_in_tortureChamber;
    char rightExecutioner[1];
};

void startStressTest(){
    
    tortureChamber_t tortureChamber;
    stack_t* stack;
    stack = &(tortureChamber.stack_in_tortureChamber);

    MACRO_stackInit(stack);
    
    int smthGoBad = 0;
    CHECK_ stackPush(stack, 1.2);
    MACRO_stackDump(*stack);

    (tortureChamber.leftExecutioner)[1] = 2;

    CHECK_ stackPush(stack, 3.4);
    MACRO_stackDump(*stack);

    stackDestroy(stack);

}