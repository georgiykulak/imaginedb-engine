#include "parser.hpp"

namespace im
{

ReturnType process( std::size_t const argc, char* const * const argv )
{
    auto opt = processArgs( argc, argv );
    ReturnType returnValue = 1;

    switch ( opt.mode )
    {
        case Mode::None:
            returnValue = internal::processCommands();
            break;
        case Mode::FromFile:
            returnValue = internal::processFile( opt.arg );
            break;
        case Mode::SQL:
            //returnValue = internal::convertFileToSQL( opt.arg );
            //break;
        default:
            //get help
            break;
    }
        
    return returnValue;
}

namespace internal
{

ReturnType processCommands()
{
    while ( true )
    {
        //TODO: Open CLI of database and provide the simplest interface
    }

    return 0;
}

ReturnType processFile( std::string const& name )
{
    //TODO: Open and interpret file

    return 0;
}

ReturnType convertFileToSQL( std::string const& name )
{
    processFile( name );
    //TODO: Open and interpret file

    return 0;
}

} // namespace internal
} // namespace im