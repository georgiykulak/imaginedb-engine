#ifndef __IMAGINEDB_ENGINE_TESTING_DEBUG_TOOLS__
#define __IMAGINEDB_ENGINE_TESTING_DEBUG_TOOLS__

#include <iostream>

constexpr const bool DEBUG_MODE = true; //replace to common config soon

#define DEBUG( out )                            \
    if constexpr ( DEBUG_MODE )                 \
        std::cout << "DEBUG: \"" << out         \
                  << "\" on line " << __LINE__  \
                  << " in file " << __FILE__    \
                  << std::endl;                 \

#define POOR_DEBUG( out )                       \
    if constexpr ( DEBUG_MODE )                 \
        std::cout << "POOR DEBUG: " << out << std::endl;

#define JUST_DEBUG()                            \
    if constexpr ( DEBUG_MODE )                 \
        std::cout << "JUST DEBUG" << std::endl;

#define DEBUG_START()                           \
    if constexpr ( DEBUG_MODE )                 \
        std::cout << "DEBUG START" << std::endl;

#define DEBUG_FINISH()                          \
    if constexpr ( DEBUG_MODE )                 \
        std::cout << "DEBUG FINISH" << std::endl;

#endif /* __IMAGINEDB_ENGINE_TESTING_DEBUG_TOOLS__ */