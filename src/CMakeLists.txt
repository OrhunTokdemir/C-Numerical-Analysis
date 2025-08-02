# Source files for the numerical analysis library
set(NUMERICAL_ANALYSIS_SOURCES
    bisection_method.c
    common.c
    derivative.c
    gauss_seidel.c
    linear_algebra.c
    newton_raphson.c
    regula_falsi_method.c
    secant_method.c
    # Add new methods here:
    # new_method.c
)

# Create static library
add_library(numerical_analysis STATIC ${NUMERICAL_ANALYSIS_SOURCES})

# Set library properties
set_target_properties(numerical_analysis PROPERTIES
    OUTPUT_NAME "numerical_analysis"
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
)

# Link math library
target_link_libraries(numerical_analysis m)

# Include directories for the library
target_include_directories(numerical_analysis PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
    $<INSTALL_INTERFACE:include/numerical_analysis>
)

# Install the library
install(TARGETS numerical_analysis
    EXPORT NumericalAnalysisTargets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)
