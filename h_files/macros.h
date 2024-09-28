#ifndef MACROS
#define MACROS

//-------------DEBUG MACRO---------------
#ifdef NDEBUG
#define ON_DEBUG(...) __VA_ARGS__

#else
#define ON_DEBUG(...)

#endif

//-------------MACRO FUNCTIONS----------------
#define MACRO_stackInit(stack) stackInit((&stack) ON_DEBUG(, (__FILE__), (__LINE__)))

#define MACRO_stackAssertFunction(stack) stackAssertFunc((&stack), (__FILE__), (__LINE__), (__func__))

#define MACRO_stackDump(stack) stackDump((&stack) ON_DEBUG(, (#stack), (__FILE__), (__LINE__), (__func__)))

#endif