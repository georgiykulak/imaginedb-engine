cmake_minimum_required( VERSION 3.9 )

project(
    imaginedb-engine
        VERSION 0.0
    
    DESCRIPTION
        "Engine for common purpose database management system"
    
    LANGUAGES
        CXX
)

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED True )

add_library(
    im_processor STATIC
        src/processor/processor.cpp
        src/processor/processor.hpp
)

target_include_directories( im_processor PUBLIC processor )

add_executable( imaginedb-engine src/main.cpp )

target_link_libraries( imaginedb-engine PUBLIC im_processor )