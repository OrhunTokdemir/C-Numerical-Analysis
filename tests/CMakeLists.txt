# Test programs

# Check if we have any test files
file(GLOB TEST_SOURCES "*.c")

if(TEST_SOURCES)
    # Create test executables
    foreach(TEST_SOURCE ${TEST_SOURCES})
        # Get filename without extension
        get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
        
        # Create test executable
        add_executable(test_${TEST_NAME} ${TEST_SOURCE})
        
        # Link with the numerical analysis library
        target_link_libraries(test_${TEST_NAME} numerical_analysis m)
        
        # Add as a test
        add_test(NAME ${TEST_NAME} COMMAND test_${TEST_NAME})
        
        # Set output directory
        set_target_properties(test_${TEST_NAME} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests
        )
    endforeach()
else()
    message(STATUS "No test files found in tests directory")
endif()
