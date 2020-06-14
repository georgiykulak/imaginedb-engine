#ifndef __IMAGINEDB_ENGINE_PROCESSOR_PARSER__
#define __IMAGINEDB_ENGINE_PROCESSOR_PARSER__

#include "processor.hpp"

namespace
{

enum Mode
{
    None = 0,
    SQL,
    FromFile,
    Help
};

struct Command
{
    Command()
        : hasArg( false )
        , mode( Mode::None )
        , arg( "" )
    {}

    bool hasArg;
    Mode mode;
    std::string arg;
};

} // namespace

static Command processArgs( std::size_t const argc, char* const * const argv )
{
    if ( argc < 2 )
        return Command();

    Command tmp;
    std::vector< std::string > args;

    for ( std::size_t i = 0; i < argc; ++i )
        args.push_back( argv[ i ] );

    //TODO: analize what mode is needed

    return tmp;
}

#endif /* __IMAGINEDB_ENGINE_PROCESSOR_PARSER__ */