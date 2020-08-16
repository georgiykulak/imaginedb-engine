#include "number.hpp"

namespace im
{
namespace container
{

Number::Number()
    :   m_number{ 0 }
{}

//----------------------------------------------------------------------------//

Number::Number( MaxFloat maxFloat )
{
    /*m_is_negative = maxFloat < 0;

    maxFloat = std::abs( maxFloat );
    
    auto beforeSeparator = static_cast< Size >( maxFloat );
    auto afterSeparator = maxFloat - beforeSeparator;

    m_number.push_back( beforeSeparator );

    m_left_shift_size = afterSeparator * 1E10;*/

    // TODO
}

//----------------------------------------------------------------------------//

Number::Number( Number && number )
    :   m_number( std::move( number.m_number ) )
    ,   m_left_shift_size( number.m_left_shift_size )
    ,   m_is_negative( number.m_is_negative )
    ,   m_is_periodical( number.m_is_periodical )
    ,   m_is_infinite( number.m_is_infinite )
    ,   m_is_NaN( number.m_is_NaN )
{
    number.~Number();
}

//----------------------------------------------------------------------------//

Number::Number( Number const& number )
    :   m_number( number.m_number )
    ,   m_left_shift_size( number.m_left_shift_size )
    ,   m_is_negative( number.m_is_negative )
    ,   m_is_periodical( number.m_is_periodical )
    ,   m_is_infinite( number.m_is_infinite )
    ,   m_is_NaN( number.m_is_NaN )
{}

//----------------------------------------------------------------------------//

Number& Number::operator=( Number&& number )
{
    m_number          = std::move( number.m_number );
    m_left_shift_size = number.m_left_shift_size;
    m_is_negative     = number.m_is_negative;
    m_is_periodical   = number.m_is_periodical;
    m_is_infinite     = number.m_is_infinite;
    m_is_NaN          = number.m_is_NaN;
    
    number.~Number();

    return *this;
}

//----------------------------------------------------------------------------//
    
Number& Number::operator=( Number const& number )
{
    m_number          = number.m_number;
    m_left_shift_size = number.m_left_shift_size;
    m_is_negative     = number.m_is_negative;
    m_is_periodical   = number.m_is_periodical;
    m_is_infinite     = number.m_is_infinite;
    m_is_NaN          = number.m_is_NaN;

    return *this;
}

//----------------------------------------------------------------------------//

Number Number::operator+() const
{
    return *this;
}

//----------------------------------------------------------------------------//

Number Number::operator-() const
{
    Number tmp = *this;
    tmp.abs();

    return tmp;
}

//----------------------------------------------------------------------------//

Number Number::operator+( Number const& number ) const
{
    if ( m_is_negative && number.m_is_negative )
        return add( -( *this ), -number ).abs();

    else if ( m_is_negative && !number.m_is_negative )
        return sub( -( *this ), number ).abs();

    else if ( !m_is_negative && number.m_is_negative )
        return sub( *this, number );
        
    else
        return add( *this, number );
}

//----------------------------------------------------------------------------//

Number Number::operator-( Number const& number ) const
{
    return Number::operator+( -number );
}

//----------------------------------------------------------------------------//

Number Number::operator*( Number const& number ) const
{
    return mul( *this, number );
}

//----------------------------------------------------------------------------//

Number Number::operator/( Number const& number ) const
{
    return div( *this, number );
}

//----------------------------------------------------------------------------//

Number Number::operator%( Number const& number ) const
{
    Number tmp;

    // TODO: Algorithm

    return tmp;
}

//----------------------------------------------------------------------------//

/*Number Number::operator++( int )
{
    *this += 1;

    return *this - 1;
}

//----------------------------------------------------------------------------//

Number& Number::operator++()
{
    return *this += 1;
}

//----------------------------------------------------------------------------//

Number& Number::operator--( int )
{
    *this -= 1;

    return *this + 1;
}

//----------------------------------------------------------------------------//

Number& Number::operator--()
{
    return *this -= 1;
}*/

//----------------------------------------------------------------------------//

Number& Number::operator+=( Number const& number )
{
    *this = *this + number;

    return *this;
}

//----------------------------------------------------------------------------//

Number& Number::operator-=( Number const& number )
{
    *this = *this - number;

    return *this;
}

//----------------------------------------------------------------------------//

Number& Number::operator*=( Number const& number )
{
    *this = *this * number;

    return *this;
}

//----------------------------------------------------------------------------//

Number& Number::operator/=( Number const& number )
{
    *this = *this / number;

    return *this;
}

//----------------------------------------------------------------------------//

Number& Number::operator%=( Number const& number )
{
    *this = *this % number;

    return *this;
}

//----------------------------------------------------------------------------//

Number::operator bool() const
{
    return !m_is_NaN && !m_is_infinite;
}

//----------------------------------------------------------------------------//

Number::operator std::string() const
{
    return toString();
}

//----------------------------------------------------------------------------//

bool Number::isNegative() const
{
    return m_is_negative;
}

//----------------------------------------------------------------------------//

bool Number::isPeriodical() const
{
    return m_is_periodical;
}

//----------------------------------------------------------------------------//

bool Number::isInfinite() const
{
    return m_is_infinite;
}

//----------------------------------------------------------------------------//

bool Number::isNaN() const
{
    return m_is_NaN;
}

//----------------------------------------------------------------------------//

Number& Number::pow( Number const& number )
{
    // TODO: Algorithm

    return *this;
}

//----------------------------------------------------------------------------//

Number& Number::abs()
{
    m_is_negative = !m_is_negative;

    return *this;
}

//----------------------------------------------------------------------------//

//std::stoull for from string conversion
std::string Number::toString() const
{
    std::string res;

    if ( m_is_NaN )
        return NaN;
    
    if ( m_is_infinite )
        return infinity;

    if ( m_is_negative )
        res += '-';
    
    auto integerDigits = countDigits( m_number ) - m_left_shift_size;
    decltype( m_left_shift_size ) k = 0;
    for ( auto i: m_number )
    {
        std::string tmp;

        do
        {
            tmp.push_back( ( i % 10 ) + '0' );
        }
        while ( i /= 10 );
        
        std::reverse( tmp.begin(), tmp.end() );

        for ( auto j: tmp )
        {
            if ( k == integerDigits )
                res += separator;

            res += j;
            ++k;
        }
    }

    return res;
}

//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//

Number::Size Number::numberLength( Size integer ) const
{
    Size count = 0;

    do
        ++count;
    while ( integer /= 10 );

    return count;
}

Number::Size Number::countDigits( Array const& number ) const
{
    Size sz = 0;

    for ( auto const& i: number )
        sz += numberLength( i );

    return sz;
}

//----------------------------------------------------------------------------//

Number Number::add( Number const& lft, Number const& rht ) const
{
    IM_ASSERT( lft.isNegative(), "First argument is negative in Number::add()" );
    IM_ASSERT( rht.isNegative(), "Second argument is negative in Number::add()" );
    
    // TODO: ALgorithm

    return Number();
}

//----------------------------------------------------------------------------//

Number Number::sub( Number const& lft, Number const& rht ) const
{
    IM_ASSERT( lft.isNegative(), "First argument is negative in Number::sub()" );
    IM_ASSERT( rht.isNegative(), "Second argument is negative in Number::sub()" );
    
    // TODO: ALgorithm

    return Number();
}

//----------------------------------------------------------------------------//

Number Number::mul( Number const& lft, Number const& rht ) const
{
    Number num;

    if ( lft == Number( 0 ) || rht == Number( 0 ) )
        return 0;

    // TODO: ALgorithm

    num.m_is_negative = lft.m_is_negative != rht.m_is_negative;

    return num;
}

//----------------------------------------------------------------------------//

Number Number::div( Number const& lft, Number const& rht ) const
{
    Number num;

    if ( rht == Number( 0 ) )
    {
        num.m_is_infinite = true;
        return num;
    }

    // TODO: ALgorithm

    num.m_is_negative = lft.m_is_negative != rht.m_is_negative;

    return num;
}

} // namespace container
} // namespace im