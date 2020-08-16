#ifndef __IMAGINEDB_ENGINE_TESTING_TEST_HELPERS__
#define __IMAGINEDB_ENGINE_TESTING_TEST_HELPERS__

#include "gtest/gtest.h"

#define TESTBENCH()                         \
    int main( int c, char** v )             \
    {                                       \
        ::testing::InitGoogleTest( &c, v ); \
        return RUN_ALL_TESTS();             \
    }

#endif /* __IMAGINEDB_ENGINE_TESTING_TEST_HELPERS__ */
