#include "processor/processor.hpp"

int main( int argc, char** argv )
{
    std::cout << "Welcome to ImagineDB!" << std::endl;

    auto exitCode = im::process( argc, argv );

    return static_cast< int >( exitCode );
}
