#ifndef __IMAGINEDB_ENGINE_DATABASES_RELATIONAL_TABLE__
#define __IMAGINEDB_ENGINE_DATABASES_RELATIONAL_TABLE__

#include <vector>
#include <memory>

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
    using String = std::string;
    using Attributes = std::vector< String >;
    using SmartPointer = std::shared_ptr< type::BaseType >;
    using Tuple = std::vector< SmartPointer >;
    using Container = std::vector< Tuple >;

private:
    Container m_tuples;
    Attributes m_attributes;
    Tuple::size_type m_tuple_size;
};

} // namespace relational
} // namespace database
} // namespace im

#endif /* __IMAGINEDB_ENGINE_DATABASES_RELATIONAL_TABLE__ */