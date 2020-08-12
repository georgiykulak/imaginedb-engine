#include <type_traits>

#include <testing/test_helpers.hpp>
#include <containers/number/number.hpp>

using im::container::Number;

TEST( Creation, Static_types )
{
    EXPECT_EQ( ( std::is_same_v< Number::Array, std::vector< char > > ), true );
    EXPECT_EQ( ( std::is_same_v< Number::MaxFloat, long double > ), true );
    EXPECT_EQ( sizeof( Number ) % 8, 0 );
    EXPECT_EQ( sizeof( Number::Array ) % 8, 0 );
}

TEST( Creation, Static_values )
{
    EXPECT_EQ( Number::Sign::plus, '+' );
    EXPECT_EQ( Number::Sign::minus, '-' );
    EXPECT_EQ( Number::Periodical::no, '#' );
    EXPECT_EQ( Number::Periodical::yes, '&' );

    if constexpr ( DOT_SEPARATOR )
        EXPECT_EQ( Number::separator, '.' );
    else
        EXPECT_EQ( Number::separator, ',' );
    
    EXPECT_EQ( std::string( Number::infinity ), std::string( "<inf>" ) );
    EXPECT_EQ( std::string( Number::notReal ), std::string( "<NaN>" ) );
}

TEST( Creation, Default_constructor )
{
    im::container::Number number;
    EXPECT_EQ( number.getRaw(), std::string( "+0.0#" ) );
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