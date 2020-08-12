#ifndef __IMAGINEDB_ENGINE_TESTING_DEBUG_TOOLS__
#define __IMAGINEDB_ENGINE_TESTING_DEBUG_TOOLS__

#include <iostream>

#define DEBUG( out )                        \
{                                           \
    std::cout << "DEBUG: \"" << out         \
              << "\" on line " << __LINE__  \
              << " in file " << __FILE__    \
              << std::endl;                 \
}

#define POOR_DEBUG( out )                   \
    std::cout << "POOR DEBUG: " << out << std::endl;

#define JUST_DEBUG()                        \
    std::cout << "JUST DEBUG" << std::endl;

#define DEBUG_START()                       \
    std::cout << "DEBUG START" << std::endl;

#define DEBUG_FINISH()                      \
    std::cout << "DEBUG FINISH" << std::endl;

#endif /* __IMAGINEDB_ENGINE_TESTING_DEBUG_TOOLS__ */