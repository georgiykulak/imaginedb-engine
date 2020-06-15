#ifndef __IMAGINEDB_ENGINE_TYPES_NUM__
#define __IMAGINEDB_ENGINE_TYPES_NUM__

#include "base_type.hpp"

namespace im
{
namespace type
{

class Num : public BaseType
{
public:
    static std::string const type_name;
    using Container = char; // replace soon with custom class Number based on char array or
                            // provide multimethods and multiple Num classes

    Num();

private:
    Container m_attribute;
};

std::string const Num::type_name = "Num";

} // namespace type
} // namespace im

#endif /* __IMAGINEDB_ENGINE_TYPES_NUM__ */