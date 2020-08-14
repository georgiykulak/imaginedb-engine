#include <type_traits>

#include <testing/test_helpers.hpp>
#include <containers/number/number.hpp>

using im::container::Number;

TEST( Creation, Static_types )
{
    EXPECT_EQ
    (
        ( std::is_same_v< Number::Array, std::vector< unsigned long long> > ),
        true
    );
    EXPECT_EQ( ( std::is_same_v< Number::MaxFloat, long double > ), true );
    EXPECT_EQ( sizeof( Number ), 32 );
    EXPECT_EQ( sizeof( Number::Array ), 24 );
}

TEST( Creation, Static_values )
{
    if constexpr ( DOT_SEPARATOR )
        EXPECT_EQ( Number::separator, '.' );
    else
        EXPECT_EQ( Number::separator, ',' );
    
    EXPECT_EQ( std::string( Number::infinity ), std::string( "<infinity>" ) );
    EXPECT_EQ( std::string( Number::NaN ), std::string( "<NaN>" ) );

    EXPECT_EQ( Number::max_digits, 18 );
    EXPECT_EQ( Number::max_integer, 1E19 );
}

TEST( Creation, Default_constructor )
{
    im::container::Number number;
    EXPECT_EQ( number.toString(), std::string( "0.0" ) );
}

TEST( Creation, Copy_constructors )
{
    // TODO
}

TEST( Creation, Move_constructors )
{
    // TODO
}

TEST( Creation, Other_constructors )
{
    // TODO
}

TESTBENCH();