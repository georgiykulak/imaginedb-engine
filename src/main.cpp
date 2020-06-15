#include "processor/processor.hpp"

int main( int argc, char** argv )
{
    auto exitCode = im::process( argc, argv );

    return static_cast< int >( exitCode );
}
