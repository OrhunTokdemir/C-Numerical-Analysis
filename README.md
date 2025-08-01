# C-Numerical-Analysis
Nümerik analiz metotlarının standart c ile uygulanması

## Building the Project

### Recommended: CMake (Modern)
```bash
# Build all
.\build.bat

# Or manually:
mkdir build && cd build
cmake -G "MinGW Makefiles" -DCMAKE_C_COMPILER=gcc ..
cmake --build . --config Release

# Clean
.\clean.bat
```

### Alternative: Traditional Make (Legacy)
```bash
make all          # Build library and examples
make library      # Build library only
make clean        # Clean build files
```

## Project Structure
- `src/` - Library source code
- `include/` - Header files  
- `examples/` - Example programs
- `build/` - CMake build output (ignored by git)
- `CMakeLists.txt` - CMake configuration
- `Makefile` - Traditional make configuration (backup)
