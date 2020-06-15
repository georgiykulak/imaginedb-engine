#ifndef __IMAGINEDB_ENGINE_PROCESSOR_PROCESSOR__
#define __IMAGINEDB_ENGINE_PROCESSOR_PROCESSOR__

#include <vector>
#include <string>

namespace im
{

using ReturnType = int;

ReturnType process( std::size_t const argc, char* const * const argv );

namespace internal
{

ReturnType processCommands();

ReturnType processFile( std::string const& name );

ReturnType convertFileToSQL( std::string const& name );

} // namespace internal
} // namespace im

#endif /* __IMAGINEDB_ENGINE_PROCESSOR_PROCESSOR__ */