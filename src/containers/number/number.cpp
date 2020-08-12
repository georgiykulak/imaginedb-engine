#include "number.hpp"

namespace im
{
namespace container
{

Number::Number()
    :   m_number( toArray( 0 ) )
{}

//----------------------------------------------------------------------------//

Number::Number( MaxFloat maxFloat )
    :   m_number( toArray( maxFloat ) )
{}

//----------------------------------------------------------------------------//

Number::Number( Number && number )
    :   m_number( std::move( number.m_number ) )
{
    number.~Number();
}

//----------------------------------------------------------------------------//

Number::Number( Number const& number )
    :   m_number( number.m_number )
{}

//----------------------------------------------------------------------------//

Number& Number::operator=( Number&& number )
{
    m_number = std::move( number.m_number );
    number.~Number();

    return *this;
}

//----------------------------------------------------------------------------//
    
Number& Number::operator=( Number const& number )
{
    m_number = number.m_number;

    return *this;
}

//----------------------------------------------------------------------------//

std::string Number::toString()
{
    std::string tmp;

    if ( !m_number.empty() && m_number[ 0 ] == Sign::minus )
        tmp += Sign::minus;

    for ( std::string::size_type i = 1; i < m_number.size() - 1; ++i )
        tmp += m_number[ i ];
    
    return tmp;
}
//----------------------------------------------------------------------------//

std::string Number::getRaw()
{
    std::string tmp;

    for ( auto const c: m_number )
        tmp += c;
    
    return tmp;
}

////////////////////////////////////////////////////////////////////////////////

Number::Array Number::toArray( MaxFloat maxFloat ) const
{
    Number::Array tmp;

    auto sign = maxFloat < 0 ? Sign::minus : Sign::plus;

    maxFloat = std::abs( maxFloat );

    auto beforeSeparator = static_cast< long long >( maxFloat );
    auto afterSeparator = maxFloat - beforeSeparator;

    do
    {
        tmp.push_back( ( beforeSeparator % 10 ) + '0' );
    } while ( beforeSeparator /= 10 );

    tmp.push_back( sign );
    std::reverse( tmp.begin(), tmp.end() );
    tmp.push_back( separator );

    afterSeparator *= 10;
    do
    {
        tmp.push_back( static_cast< char >( afterSeparator ) + '0' );
        afterSeparator -= static_cast< long long >( afterSeparator );
    } while ( afterSeparator *= 10 );

    tmp.push_back( Periodical::no );

    return tmp;
}

} // namespace container
} // namespace im