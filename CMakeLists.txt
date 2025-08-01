cmake_minimum_required(VERSION 3.10)

# Project information
project(NumericalAnalysis 
    VERSION 1.0.0 
    DESCRIPTION "C Numerical Analysis Library"
    LANGUAGES C)

# Set C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Add compiler flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
set(CMAKE_C_FLAGS_DEBUG "-g -O0")
set(CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG")

# Include directories
include_directories(include)

# Add subdirectories
add_subdirectory(src)
add_subdirectory(examples)

# Create executables for standalone programs in root directory
set(STANDALONE_PROGRAMS
    bisectionMethod.c
    GaussSiedel.c
    main.c
    NewtonRhapson.c
    RegulaFalsiMethod.c
    SekantMethod.c
)

foreach(PROGRAM ${STANDALONE_PROGRAMS})
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${PROGRAM}")
        get_filename_component(PROGRAM_NAME ${PROGRAM} NAME_WE)
        add_executable(${PROGRAM_NAME} ${PROGRAM})
        target_link_libraries(${PROGRAM_NAME} numerical_analysis m)
        set_target_properties(${PROGRAM_NAME} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
        )
    endif()
endforeach()

# Option to build tests
option(BUILD_TESTS "Build test programs" ON)
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

# Installation settings
set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/install" CACHE PATH "Installation prefix")

# Install headers
install(DIRECTORY include/ 
    DESTINATION include/numerical_analysis
    FILES_MATCHING PATTERN "*.h")

# Create package config file
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/NumericalAnalysisConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

# Export targets
install(EXPORT NumericalAnalysisTargets
    FILE NumericalAnalysisTargets.cmake
    NAMESPACE NumericalAnalysis::
    DESTINATION lib/cmake/NumericalAnalysis
)

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/NumericalAnalysisConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/NumericalAnalysisConfig.cmake"
    INSTALL_DESTINATION lib/cmake/NumericalAnalysis
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/NumericalAnalysisConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/NumericalAnalysisConfigVersion.cmake"
    DESTINATION lib/cmake/NumericalAnalysis
)
