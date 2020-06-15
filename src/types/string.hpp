#ifndef __IMAGINEDB_ENGINE_TYPES_STRING__
#define __IMAGINEDB_ENGINE_TYPES_STRING__

#include "base_type.hpp"

namespace im
{
namespace type
{

class String : public BaseType
{
public:
    static std::string const type_name;
    using Container = std::string; // replace soon with more optimized and lightweight container

    String();

private:
    Container m_attribute;
};

std::string const String::type_name = "String";

} // namespace type
} // namespace im

#endif /* __IMAGINEDB_ENGINE_TYPES_STRING__ */