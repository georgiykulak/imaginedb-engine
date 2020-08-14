#ifndef __IMAGINEDB_ENGINE_CONTAINERS_NUMBER_NUMBER__
#define __IMAGINEDB_ENGINE_CONTAINERS_NUMBER_NUMBER__

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
    using Array = std::vector< char >;
    using MaxFloat = long double;

    enum Sign : char { plus = '+', minus = '-' };
    enum Periodical : char { no = '#', yes = '&' };

    static constexpr const char  separator = DOT_SEPARATOR ? '.' : ',';
    static constexpr const char* infinity = "<inf>";
    static constexpr const char* notReal = "<NaN>";

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

    std::string toString();
    std::string getRaw();

private:
    Array m_number;

    Array toArray( MaxFloat ) const;
};

} // namespace container
} // namespace im

#endif /* __IMAGINEDB_ENGINE_CONTAINERS_NUMBER_NUMBER__ */