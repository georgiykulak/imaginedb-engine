#ifndef __IMAGINEDB_ENGINE_TYPES_TIME__
#define __IMAGINEDB_ENGINE_TYPES_TIME__

#include <chrono>
#include "base_type.hpp"

namespace im
{
namespace type
{

class Time : public BaseType
{
public:
    static std::string const type_name;
    using Container = std::chrono::utc_clock<std::chrono::microseconds>; // replace soon with smth like variant of utc and local time

    Time();

private:
    Container m_attribute;
};

std::string const Time::type_name = "Time";

} // namespace type
} // namespace im

#endif /* __IMAGINEDB_ENGINE_TYPES_TIME__ */