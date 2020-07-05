#ifndef __IMAGINEDB_ENGINE_DATABASES_RELATIONAL_DATABASE__
#define __IMAGINEDB_ENGINE_DATABASES_RELATIONAL_DATABASE__

#include <vector>

#include "relational/table.hpp"

namespace im
{
namespace database
{

class Database
{
public:
    using RelationalContainer = std::vector< relational::Table >;

private:
    RelationalContainer m_tables;
};

} // namespace database
} // namespace im

#endif /* __IMAGINEDB_ENGINE_DATABASES_RELATIONAL_DATABASE__ */