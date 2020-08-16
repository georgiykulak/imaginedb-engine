#ifndef __IMAGINEDB_ENGINE_TESTING_ASSERT__
#define __IMAGINEDB_ENGINE_TESTING_ASSERT__

#include <cassert>

constexpr const bool PROD_ASSERT = true; //replace to common config soon

#define IM_ASSERT( exp, msg ) \
    if constexpr ( PROD_ASSERT ) assert( ( (void)msg, exp ) );

#endif /* __IMAGINEDB_ENGINE_TESTING_ASSERT__ */
