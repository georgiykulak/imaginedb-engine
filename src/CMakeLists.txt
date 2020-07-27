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

# Library for parsing and processing CLI options
add_library(
    im_processor STATIC
    ${CMAKE_SOURCE_DIR}/processor/processor.cpp
    ${CMAKE_SOURCE_DIR}/processor/processor.hpp
)

add_executable( imaginedb-engine ${CMAKE_SOURCE_DIR}/main.cpp )

target_link_libraries( imaginedb-engine PUBLIC im_processor )
