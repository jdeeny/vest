cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(vest)
set( version 0.1 )

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target)

add_definitions(-Wall -Werror)

add_subdirectory( lib )
add_subdirectory( ref )
add_subdirectory( test )
