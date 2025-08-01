@echo off
echo Building Numerical Analysis Library with CMake...

REM Create build directory
if not exist "build" mkdir build
cd build

REM Configure and build
cmake -G "MinGW Makefiles" -DCMAKE_C_COMPILER=gcc ..
cmake --build . --config Release

REM Optionally run tests
echo.
echo Running tests...
ctest --output-on-failure

echo.
echo Build complete! Executables are in build/bin/
echo Library is in build/src/
echo Examples are in build/examples/

pause
