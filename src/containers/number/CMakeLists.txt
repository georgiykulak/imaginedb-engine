cmake_minimum_required( VERSION 3.9 )

project(
    container_number
        VERSION 1.0
    
    DESCRIPTION
        "Data type of real number"
    
    LANGUAGES
        CXX
)

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED True )

#------------------------------------------------------------------------------#
# Building project library                                                     #
#------------------------------------------------------------------------------#

add_library(
    im_container_number STATIC
    ${CMAKE_SOURCE_DIR}/number.cpp
    ${CMAKE_SOURCE_DIR}/number.hpp
)

target_include_directories(
    im_container_number PUBLIC ${CMAKE_SOURCE_DIR}/../../
)

#------------------------------------------------------------------------------#
# Add GTest external library and useful functions                              #
#------------------------------------------------------------------------------#

configure_file( ../../CMakeLists.txt.in googletest-download/CMakeLists.txt )

execute_process( COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download
)
if ( result )
  message( FATAL_ERROR "CMake step for googletest failed: ${result}" )
endif()

execute_process( COMMAND ${CMAKE_COMMAND} --build .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download
)
if ( result )
    message( FATAL_ERROR "Build step for googletest failed: ${result}" )
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set( gtest_force_shared_crt ON CACHE BOOL "" FORCE )

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(
    ${CMAKE_CURRENT_BINARY_DIR}/googletest-src
    ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
    EXCLUDE_FROM_ALL
)

#------------------------------------------------------------------------------#

function( add_gtest
    testName pathToTest
)
    add_executable( ${testName} ${pathToTest} )
    target_link_libraries( ${testName} im_container_number )
    target_link_libraries( ${testName} gtest_main )
    add_test( NAME ${testName}_unittest COMMAND ${testName} )
endfunction()

#------------------------------------------------------------------------------#
# Tests                                                                        #
#------------------------------------------------------------------------------#

add_gtest( creations  tests/creations.cpp )
add_gtest( casts      tests/casts.cpp )
add_gtest( operations tests/operations.cpp )