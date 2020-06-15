#ifndef __IMAGINEDB_ENGINE_DATABASES_RELATIONAL_DATABASE__
#define __IMAGINEDB_ENGINE_DATABASES_RELATIONAL_DATABASE__

#include <vector>

#include "table.hpp"

namespace im
{
namespace database
{
namespace relational
{

class Database
{
public:
    using Container = std::vector< Table >;

private:
    Container m_tables;
};

} // namespace relational
} // namespace database
} // namespace im

#endif /* __IMAGINEDB_ENGINE_DATABASES_RELATIONAL_DATABASE__ */