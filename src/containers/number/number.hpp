#ifndef __IMAGINEDB_ENGINE_CONTAINERS_NUMBER_NUMBER__
#define __IMAGINEDB_ENGINE_CONTAINERS_NUMBER_NUMBER__

#include <cmath>
#include <array>
#include <vector>
#include <string>
#include <algorithm>

#include <testing/assert.hpp>

constexpr const bool DOT_SEPARATOR = true; //replace to common config soon

namespace im
{
namespace container
{

class Number final
{
public:
    using Size = unsigned long long;
    using Array = std::vector< Size >;

    static constexpr const char* infinity = "<infinity>";
    static constexpr const char* NaN = "<NaN>";
    static constexpr const char  separator = DOT_SEPARATOR ? '.' : ',';
    static constexpr const unsigned max_digits = sizeof( Size ) * 8;
    static constexpr const Size precision = sizeof( Size );
    static constexpr const unsigned f_precision = 6;

    ~Number() = default;

    Number();

    Number( std::string const& ); // TODO
    
    Number( Number&& );
    Number( Number const& );

    Number& operator=( Number&& );
    Number& operator=( Number const& );

    Number operator+() const;
    Number operator-() const;
    Number operator+( Number const& ) const;
    Number operator-( Number const& ) const;
    Number operator*( Number const& ) const;
    Number operator/( Number const& ) const;
    Number operator%( Number const& ) const; // TODO
    // TODO:
    /*Number& operator++( int );
    Number& operator++();
    Number& operator--( int );
    Number& operator--();*/
    Number& operator+=( Number const& );
    Number& operator-=( Number const& );
    Number& operator*=( Number const& );
    Number& operator/=( Number const& );
    Number& operator%=( Number const& );

    bool operator<=>( Number const& ) const = default;
    
    operator bool() const;
    operator std::string() const;

    bool isNegative() const;
    bool isPeriodical() const;
    bool isInfinite() const;
    bool isNaN() const;

    Number& pow( Number const& ); // TODO
    Number& abs();

    std::string toString() const;

private:
    Array m_number;
    Size m_float_shift_size = 0; // counts decimal shift from float to int
    bool m_is_negative = false;
    bool m_is_periodical = false;
    bool m_is_infinite = false;
    bool m_is_NaN = false;

    Number add( Number const&, Number const& ) const; // TODO
    Number sub( Number const&, Number const& ) const; // TODO
    Number mul( Number const&, Number const& ) const; // TODO
    Number div( Number const&, Number const& ) const; // TODO
};

} // namespace container
} // namespace im

#endif /* __IMAGINEDB_ENGINE_CONTAINERS_NUMBER_NUMBER__ */