#ifndef __IMAGINEDB_ENGINE_TYPES_DATE__
#define __IMAGINEDB_ENGINE_TYPES_DATE__

#include <chrono>
#include "base_type.hpp"

namespace im
{
namespace type
{

class Date : public BaseType
{
public:
    static std::string const type_name;
    using Container = std::chrono::utc_clock<std::chrono::microseconds>; // replace soon with smth like tm from <ctime>

    Date();

private:
    Container m_attribute;
};

std::string const Date::type_name = "Date";

} // namespace type
} // namespace im

#endif /* __IMAGINEDB_ENGINE_TYPES_DATE__ */