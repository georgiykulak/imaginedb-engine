#include "number.hpp"

namespace im
{
namespace container
{

Number::Number()
    :   m_integer{ 0 }
{}

//----------------------------------------------------------------------------//

Number::Number( MaxFloat maxFloat )
{
    m_is_negative = maxFloat < 0;

    maxFloat = std::abs( maxFloat );
    
    auto beforeSeparator = static_cast< unsigned long long >( maxFloat );
    auto afterSeparator = maxFloat - beforeSeparator;

    m_integer.push_back( beforeSeparator );

    m_fractional = afterSeparator * 1E10;
}

//----------------------------------------------------------------------------//

Number::Number( Number && number )
    :   m_integer( std::move( number.m_integer ) )
    ,   m_fractional( number.m_fractional )
{
    number.~Number();
}

//----------------------------------------------------------------------------//

Number::Number( Number const& number )
    :   m_integer( number.m_integer )
    ,   m_fractional( number.m_fractional )
{}

//----------------------------------------------------------------------------//

Number& Number::operator=( Number&& number )
{
    m_integer = std::move( number.m_integer );
    m_fractional = number.m_fractional;
    
    number.~Number();

    return *this;
}

//----------------------------------------------------------------------------//
    
Number& Number::operator=( Number const& number )
{
    m_integer = number.m_integer;
    m_fractional = number.m_fractional;

    return *this;
}

//----------------------------------------------------------------------------//
//std::stoull for from string conversion
std::string Number::toString() const
{
    std::string tmp;

    if ( m_is_negative )
        tmp += '-';
    
    for ( auto const& i: m_integer )
        tmp.append( std::to_string( i ) );

    tmp += separator;
    
    tmp.append( std::to_string( m_fractional ) );
    
    return tmp;
}

} // namespace container
} // namespace im