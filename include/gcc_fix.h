// include/gcc_fix.h
#pragma once

#ifdef __GNUC__
    // Disable Apple's availability macros
    #define API_AVAILABLE(...)
    #define API_UNAVAILABLE(...)
    
    // Workaround for dispatch_block_t (GCD)
    typedef void* dispatch_block_t;
#endif
