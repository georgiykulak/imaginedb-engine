#include "number.hpp"

namespace im
{
namespace container
{

static inline bool isSigned( std::string const& str )
{
    return !str.empty() && ( str[ 0 ] == '-' || str[ 0 ] == '+' );
}

static inline bool validate( std::string const& str )
{
    bool flagSignPresent = false;
    bool flagSepNotRpts = true;

    if ( str == std::string( Number::infinity ) ||
         str == std::string( Number::NaN ) )
        return true;

    if ( isSigned( str ) )
        flagSignPresent = true;

    auto sz = str.size();
    for ( std::string::size_type i = flagSignPresent; i < sz; ++i )
    {
        if ( str[ i ] < '0' || str[ i ] > '9' )
        {
            if ( str[ i ] == Number::separator )
            {
                if ( flagSepNotRpts )
                {
                    flagSepNotRpts = false;
                    continue;
                }
            }

            return false;
        }
    }

    return true;
}

static inline void removeSymbols( std::string& str, Number::Size& fss )
{
    auto sep = str.find( Number::separator );
    
    if ( sep != std::string::npos )
    {
        str.erase( sep );
        fss = str.size() - sep;
    }
}

static inline auto stringToVector( std::string const& str )
{
    std::vector< std::string > vec;

    // TODO: ALgorithm

    return vec;
}

static inline Number::Size countDigits( Number::Size integer )
{
    Number::Size count = 0;

    do
        ++count;
    while ( integer /= 10 );

    return count;
}

static inline Number::Size numberLength( Number::Array const& number )
{
    Number::Size sz = 0;

    for ( auto const& i: number )
        sz += countDigits( i );

    return sz;
}

//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//

Number::Number()
    :   m_number{ 0 }
{}

//----------------------------------------------------------------------------//

Number::Number( std::string const& str )
{
    if ( !validate( str ) )
        return;

    bool flagSepPresent = false;
    bool flagSigned = isSigned( str );
    if ( flagSigned )
        m_is_negative = str[ 0 ] == '-';

    auto newStr = str;
    removeSymbols( newStr, m_float_shift_size );

    auto arrStr = stringToVector( newStr );

    for ( auto const& s: arrStr )
    {
        m_number.push_back( std::stoull( s, nullptr ) );
    }
}

//----------------------------------------------------------------------------//

Number::Number( Number && number )
    :   m_number( std::move( number.m_number ) )
    ,   m_float_shift_size( number.m_float_shift_size )
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
    ,   m_float_shift_size( number.m_float_shift_size )
    ,   m_is_negative( number.m_is_negative )
    ,   m_is_periodical( number.m_is_periodical )
    ,   m_is_infinite( number.m_is_infinite )
    ,   m_is_NaN( number.m_is_NaN )
{}

//----------------------------------------------------------------------------//

Number& Number::operator=( Number&& number )
{
    m_number           = std::move( number.m_number );
    m_float_shift_size = number.m_float_shift_size;
    m_is_negative      = number.m_is_negative;
    m_is_periodical    = number.m_is_periodical;
    m_is_infinite      = number.m_is_infinite;
    m_is_NaN           = number.m_is_NaN;
    
    number.~Number();

    return *this;
}

//----------------------------------------------------------------------------//
    
Number& Number::operator=( Number const& number )
{
    m_number           = number.m_number;
    m_float_shift_size = number.m_float_shift_size;
    m_is_negative      = number.m_is_negative;
    m_is_periodical    = number.m_is_periodical;
    m_is_infinite      = number.m_is_infinite;
    m_is_NaN           = number.m_is_NaN;

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
    
    auto integerDigits = numberLength( m_number ) - m_float_shift_size;
    decltype( m_float_shift_size ) k = 0;
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

Number Number::add( Number const& lft, Number const& rht ) const
{
    IM_ASSERT( lft.isNegative(), "First argument is negative in Number::add()" );
    IM_ASSERT( rht.isNegative(), "Second argument is negative in Number::add()" );
    
    // TODO: ALgorithm
    Number res;
    Size prev = 0;
    auto const& lSize = lft.m_number.size();
    auto const& rSize = rht.m_number.size();
    res.m_number.reserve( lSize >= rSize ? lSize : rSize );

    for ( Size i = 0; i < lSize && i < rSize; ++i )
    {
        auto& tmpRes = res.m_number[ i ];
        auto const lInt = lft.m_number[ i ];
        auto const rInt = rht.m_number[ i ];

        for ( unsigned j = 0; j < max_digits; ++j )
        {
            auto mask = Size( 1 ) << j;
            auto lBin = lInt & mask;
            auto rBin = rInt & mask;
            
            if ( lBin == 0 && rBin == 0 )
            {
                tmpRes |= prev;
                prev = 0;
            }
            else if ( lBin == mask && rBin == mask )
            {
                prev = Size( 1 ) << ( j + 1 );
            }
            else
            {
                if ( prev )
                    prev = Size( 1 ) << ( j + 1 );
                else
                    tmpRes |= mask;
            }
        }
    }

    // for not added part in bigger register ...

    return res;
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

    if ( lft == Number( "0" ) || rht == Number( "0" ) )
        return Number( "0" );

    // TODO: ALgorithm

    num.m_is_negative = lft.m_is_negative != rht.m_is_negative;

    return num;
}

//----------------------------------------------------------------------------//

Number Number::div( Number const& lft, Number const& rht ) const
{
    Number num;

    if ( rht == Number( "0" ) )
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