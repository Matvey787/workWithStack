#ifndef MACROS
#define MACROS

//-------------DEBUG MACRO---------------
#ifdef DEBUG
#define ON_DEBUG(...) __VA_ARGS__

#else
#define ON_DEBUG(...)

#endif

//-------------CANARY MACRO---------------
#ifdef TURN_ON_CANARIES
#define ON_CANARY(...) __VA_ARGS__

#else
#define ON_CANARY(...)

#endif

//-------------HASH MACRO---------------
#ifdef TURN_ON_HASH
#define ON_HASH(...) __VA_ARGS__

#else
#define ON_HASH(...)

#endif

//-------------MACRO FUNCTIONS----------------

#ifdef DEBUG
#define MACRO_stackInit(...) stackInitDebug(__VA_ARGS__, (__FILE__), (__LINE__))
#define MACRO_stackAssertFunction(stack) stackAssertFunc((&stack), (__FILE__), (__LINE__), (__func__))
#define MACRO_stackDump(stack) stackDumpDebug((&stack) ON_DEBUG(, (#stack), (__FILE__), (__LINE__), (__func__)))
#else
#define MACRO_stackInit(...) stackInit(__VA_ARGS__)
#define MACRO_stackAssertFunction(...)
#define MACRO_stackDump(stack) stackDump(&stack)
#endif


#endif