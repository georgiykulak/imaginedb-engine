#ifndef __IMAGINEDB_ENGINE_CONTAINERS_NUMBER_NUMBER__
#define __IMAGINEDB_ENGINE_CONTAINERS_NUMBER_NUMBER__

#include <vector>
#include <string>
#include <cstdint>
#include <algorithm>

constexpr const bool DOT_SEPARATOR = 1;

namespace im
{
namespace container
{

class Number
{
public:
    using Digit = char;
    using Array = std::vector< Digit >;
    enum SignType : char { plus = '+', minus = '-' };

    static constexpr const Digit separator = DOT_SEPARATOR ? '.' : ',';

    Number();
    Number( intmax_t );
    Number( uintmax_t );
    Number( long double );
    Number( Number const& );
    Number operator+() const;
    Number operator-() const;
    Number operator+( Number const& ) const;
    Number operator-( Number const& ) const;
    Number operator*( Number const& ) const;
    Number operator/( Number const& ) const;
    Number operator+=( Number const& );
    Number operator-=( Number const& );
    Number operator*=( Number const& );
    Number operator/=( Number const& );
    Number pow( Number const& ) const;
    operator bool() const;
    operator std::string() const;

private:
    Array m_number;
    SignType m_sign;

    Number::Array toArray( intmax_t ) const;
    Number::Array toArray( long double ) const;
};

} // namespace container
} // namespace im

#endif /* __IMAGINEDB_ENGINE_CONTAINERS_NUMBER_NUMBER__ */