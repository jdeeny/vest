set( CMAKE_INCLUDE_CURRENT_DIR ON )

target_link_libraries ( velocity-ref )

enable_testing()
find_package(Check REQUIRED)

include_directories(${CHECK_INCLUDE_DIRS})
set( LIBS ${LIBS} ${CHECK_LIBRARIES} velocity-ref )

include_directories ( ../include )
add_executable( test-vest-ref test.c )
target_link_libraries(test-vest-ref ${LIBS})
add_test(test-vest-ref ${CMAKE_CURRENT_BINARY_DIR}/test-vest-ref)
