#ifndef __IMAGINEDB_ENGINE_DATABASES_RELATIONAL_TABLE__
#define __IMAGINEDB_ENGINE_DATABASES_RELATIONAL_TABLE__

#include <vector>

#include <types/base_type.hpp>

namespace im
{
namespace database
{
namespace relational
{

class Table
{
public:
    using Container = std::vector< type::BaseType >;

private:
    Container m_attributes;
};

} // namespace relational
} // namespace database
} // namespace im

#endif /* __IMAGINEDB_ENGINE_DATABASES_RELATIONAL_TABLE__ */