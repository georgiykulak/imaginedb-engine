#ifndef __IMAGINEDB_ENGINE_CONTAINERS_NUMBER_NUMBER__
#define __IMAGINEDB_ENGINE_CONTAINERS_NUMBER_NUMBER__

#include <array>
#include <vector>
#include <string>
#include <algorithm>

constexpr const bool DOT_SEPARATOR = true; //replace to common config soon

namespace im
{
namespace container
{

class Number final
{
public:
    using Array = std::vector< unsigned long long >;
    using MaxFloat = long double;

    static constexpr const char* infinity = "<infinity>";
    static constexpr const char* NaN = "<NaN>";
    static constexpr const char  separator = DOT_SEPARATOR ? '.' : ',';
    static constexpr const unsigned max_digits = 18;
    static constexpr const unsigned long long max_integer = 1E19;

    ~Number() = default;

    Number();

    Number( MaxFloat );
    Number( std::string && );
    Number( std::string const& );
    
    Number( Number&& );
    Number( Number const& );

    Number& operator=( Number&& );
    Number& operator=( Number const& );

    bool operator==( Number const& ) const;
    bool operator!=( Number const& ) const;

    Number operator+() const;
    Number operator-() const;
    Number operator+( Number const& ) const;
    Number operator-( Number const& ) const;
    Number operator*( Number const& ) const;
    Number operator/( Number const& ) const;
    Number operator%( Number const& ) const;
    Number operator+=( Number const& );
    Number operator-=( Number const& );
    Number operator*=( Number const& );
    Number operator/=( Number const& );
    Number operator%=( Number const& );
    
    Number pow( Number const& ) const;
    Number sqrt( /* Number const& */ ) const;
    Number abs() const;
    
    operator bool() const;
    operator std::string() const;

    std::string toString() const;

private:
    Array m_integer;
    unsigned m_fractional = 0;

    bool m_is_negative = false;
    bool m_is_periodical = false;
    bool m_is_infinite = false;
    bool m_is_NaN = false;
};

} // namespace container
} // namespace im

#endif /* __IMAGINEDB_ENGINE_CONTAINERS_NUMBER_NUMBER__ */