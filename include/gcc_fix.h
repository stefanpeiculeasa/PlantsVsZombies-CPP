// include/gcc_fix.h
#pragma once

// Neutralize Apple's availability macros for GCC
#ifdef __GNUC__
    #define API_AVAILABLE(...)
    #define API_UNAVAILABLE(...)
    
    // Define missing dispatch_block_t type
    typedef void (*dispatch_block_t)(void);
#endif
