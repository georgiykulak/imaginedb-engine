#include "number.hpp"

namespace im
{
namespace container
{

Number::Number()
{
    m_number.push_back( separator );
    m_sign = SignType::plus;
}

Number::Number( intmax_t maxInt )
{
    m_number = toArray( maxInt );
    m_sign = SignType::plus;
}

Number::Number( uintmax_t maxUInt )
{
    m_number = toArray( static_cast< intmax_t >( maxUInt ) );
    m_sign = maxUInt < 0 ? SignType::minus : SignType::plus;
}

Number::Number( long double longDouble )
{
    m_number = toArray( longDouble );
    m_sign = longDouble < 0 ? SignType::minus : SignType::plus;
}

Number::Array Number::toArray( intmax_t integer ) const
{
    Number::Array tmp;

    while ( integer )
    {
        tmp.push_back( integer % 10 );
        integer /= 10;
    }

    std::reverse( tmp.begin(), tmp.end() );

    tmp.push_back( separator );

    return tmp;
}

Number::Array Number::toArray( long double fractional ) const
{
    Number::Array tmp;

    fractional = std::abs( fractional );
    auto beforeSeparator = static_cast< intmax_t >( fractional );
    auto afterSeparator = fractional - beforeSeparator;

    tmp = toArray( beforeSeparator );

    while ( afterSeparator *= 10 )
    {
        tmp.push_back( static_cast< int >( afterSeparator ) );
        afterSeparator -= static_cast< intmax_t >( afterSeparator );
    }

    return tmp;
}

} // namespace container
} // namespace im