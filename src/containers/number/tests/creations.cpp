#include <type_traits>

#include <testing/test_helpers.hpp>
#include <containers/number/number.hpp>

using im::container::Number;

TEST( Creation, Static_types )
{
    EXPECT_EQ
    (
        ( std::is_same_v< Number::Array, std::vector< unsigned long long > > ),
        true
    );
    EXPECT_EQ( sizeof( Number ), 40 );
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

    EXPECT_EQ( Number::max_digits, 64 );
}

TEST( Creation, Default_constructor )
{
    Number number;
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
    std::vector< std::string > strings =
    {
        "1",
        "23",
        "456",
        "7890",
        "12345",
        "678901",
        "2345678",
        "90123456",
        "789012345",
        "6789012345",
        "0.1",
        "0.23",
        "0.456",
        "0.7891",
        "0.23456",
        "0.789012",
        "123.456"
    };

    std::vector< Number > numbers;

    for ( size_t i = 0; i < strings.size(); ++i )
    {
        numbers.emplace_back( strings[ i ] );
        EXPECT_EQ
        (
            strings[ i ],
            numbers[ i ].toString()
        );
    }
}

TESTBENCH();