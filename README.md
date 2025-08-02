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

### Manual Build (If CMake not available)
```bash
# Compile all source files
gcc -Wall -Wextra -std=c99 -O2 -Iinclude -c src/*.c
# Create library
ar rcs lib/libnumerical_analysis.a *.o
# Compile your program
gcc your_program.c -Iinclude -Llib -lnumerical_analysis -lm -o your_program
```

## Quick Usage

```c
#include <stdio.h>
#include <math.h>
#include "numerical_analysis.h"

// Define your function
double my_function(double x) {
    return x - pow(2, -x);  // Example function
}

int main() {
    // Use regula falsi method with function pointer
    regulaFalsiMethod(-1.0, 1.0, my_function, 0.0001);
    
    // Clean up global step counter
    if(adim) free(adim);
    return 0;
}
```

## Project Structure
- `src/` - Library source code
- `include/` - Header files  
- `examples/` - Example programs (moved from root)
- `lib/` - Compiled library (generated)
- `obj/` - Object files (generated)
- `build/` - CMake build output (ignored by git)
- `CMakeLists.txt` - CMake configuration
- `Makefile` - Traditional make configuration (backup)

## Recent Changes
- **API Breaking Change**: Numerical methods now accept function pointers for flexibility
- **Fixed**: Multiple definition errors with global variables
- **Improved**: Better library modularity and documentation
- **Reorganized**: Moved example files to `examples/` directory

For detailed API documentation, see [README_LIBRARY.md](README_LIBRARY.md).
