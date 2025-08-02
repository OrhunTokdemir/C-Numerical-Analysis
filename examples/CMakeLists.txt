# Example programs

# Get all C files in the examples directory
file(GLOB EXAMPLE_SOURCES "*.c")

# Create executables for each example
foreach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
    # Get filename without extension
    get_filename_component(EXAMPLE_NAME ${EXAMPLE_SOURCE} NAME_WE)
    
    # Create executable
    add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCE})
    
    # Link with the numerical analysis library
    target_link_libraries(${EXAMPLE_NAME} numerical_analysis m)
    
    # Set output directory
    set_target_properties(${EXAMPLE_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/examples
    )
endforeach()

# Install examples (optional)
install(TARGETS ${EXAMPLE_TARGETS}
    RUNTIME DESTINATION bin/examples
)
