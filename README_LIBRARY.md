# C Numerical Analysis Library

A comprehensive C library for numerical analysis methods including root finding algorithms, linear algebra operations, and iterative solvers.

## Features

### Root Finding Methods
- **Bisection Method**: Reliable bracketing method for finding roots
- **Newton-Raphson Method**: Fast converging method using derivatives
- **Secant Method**: Derivative-free alternative to Newton-Raphson
- **Regula Falsi Method**: False position method for root finding

### Linear Algebra Operations
- Matrix addition, subtraction, and multiplication
- LU decomposition
- Linear system solving using LU decomposition
- Support for both integer and float matrices

### Iterative Solvers
- **Gauss-Seidel Method**: Iterative solver for linear systems
- Diagonal dominance checking and automatic row swapping

### Utility Functions
- Numerical derivative calculation (forward, backward, central difference)
- Error checking functions (absolute and relative error)
- Display functions for debugging and visualization

## Library Structure

```
C-Numerical-Analysis/
├── include/                 # Header files
│   ├── numerical_analysis.h    # Main library header
│   ├── common.h                # Common utilities
│   ├── derivative.h            # Derivative calculations
│   ├── numerical_methods.h     # Root finding methods
│   ├── linear_algebra.h        # Matrix operations
│   └── gauss_seidel.h          # Iterative solver
├── src/                     # Source implementations
│   ├── common.c
│   ├── derivative.c
│   ├── numerical_methods.c
│   ├── linear_algebra.c
│   └── gauss_seidel.c
├── examples/                # Example programs
│   └── library_demo.c
├── lib/                     # Compiled library (generated)
├── obj/                     # Object files (generated)
└── Makefile                 # Build system
```

## Building the Library

### Prerequisites
- GCC compiler
- Make utility
- Standard C libraries (math.h, stdio.h, stdlib.h)

### Compilation

1. **Build everything** (library + examples):
   ```bash
   make all
   ```

2. **Build library only**:
   ```bash
   make library
   ```

3. **Build examples only**:
   ```bash
   make examples
   ```

4. **Clean build files**:
   ```bash
   make clean
   ```

### Windows (MinGW)
If using MinGW on Windows, use:
```cmd
mingw32-make all
```

## Usage

### Quick Start

1. Include the main header in your C file:
   ```c
   #include "include/numerical_analysis.h"
   ```

2. Compile your program with the library:
   ```bash
   gcc -Iinclude your_program.c -Llib -lnumerical_analysis -lm -o your_program
   ```

### Example: Finding a Root

```c
#include "include/numerical_analysis.h"
#include <stdio.h>
#include <math.h>

// Define your function
double my_function(double x) {
    return x * x - 2;  // Find square root of 2
}

int main() {
    // Use bisection method
    double root = bisectionMethod(my_function, 1.0, 2.0, 0.0001, 100);
    
    if (!isnan(root)) {
        printf("Root found: %.6f\\n", root);
    } else {
        printf("Root not found\\n");
    }
    
    return 0;
}
```

### Example: Matrix Operations

```c
#include "include/numerical_analysis.h"
#include <stdio.h>

int main() {
    // Define matrices
    float A[2][2] = {{1, 2}, {3, 4}};
    float B[2][2] = {{5, 6}, {7, 8}};
    
    // Add matrices
    float* result = fmatrisToplam((float*)A, (float*)B, 2, 2, 2, 2);
    
    // Print result
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%.1f ", result[i * 2 + j]);
        }
        printf("\\n");
    }
    
    free(result);
    return 0;
}
```

## API Reference

### Root Finding Methods

```c
double bisectionMethod(double (*f)(double), double a, double b, double tolerance, int max_iter);
double newtonRaphson(double (*f)(double), double x0, double h, double tolerance, int max_iter);
double secantMethod(double (*f)(double), double x0, double x1, double tolerance, int max_iter);
double regulaFalsiMethod(double (*f)(double), double a, double b, double tolerance, int max_iter);
```

### Linear Algebra

```c
// Matrix operations
int* matrisToplam(int* ptr0, int* ptr1, int row0, int col0, int row1, int col1);
float* fmatrisToplam(float* ptr0, float* ptr1, int row0, int col0, int row1, int col1);
float* fmatrisCikarma(float* ptr0, float* ptr1, int row0, int col0, int row1, int col1);
int* matrisCarpim(int* ptr0, int* ptr1, int row0, int col0, int row1, int col1);
float* fmatrisCarpim(float* ptr0, float* ptr1, int row0, int col0, int row1, int col1);

// LU decomposition
struct LU* LuDecomposition(float* A, int n);
void solutionByLu(struct LU* lu, float* b, float* x);
void freeLU(struct LU* lu);
```

### Iterative Solvers

```c
int CheckDiagonallyDominant(float* A, float* b, int n);
float* GaussSiedel(float* A, float* b, float* xk, int n, int max_iter, float tolerance);
```

### Derivatives

```c
double forwardDifference(double (*f)(double), double x, double h);
double backwardDifference(double (*f)(double), double x, double h);
double centralDifference(double (*f)(double), double x, double h);
```

## Examples

The `examples/` directory contains:

- `library_demo.c`: Comprehensive demonstration of all library features
- Individual method examples showing specific use cases

Run the demo:
```bash
make library_demo
./library_demo
```

## Error Handling

- Functions return `NaN` for root finding methods when convergence fails
- Matrix operations return `NULL` on dimension mismatch or other errors
- Check return values before using results
- Use `isnan()` to check for failed root finding
- Check for `NULL` pointers from matrix operations

## Performance Notes

- All algorithms use double precision floating point
- Matrix operations allocate memory dynamically - remember to `free()` results
- Iterative methods may not converge for ill-conditioned problems
- Choose appropriate tolerances and maximum iterations for your use case

## Contributing

1. Follow the existing code style
2. Add documentation for new functions
3. Include examples for new features
4. Test your changes thoroughly

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgments

- Implements standard numerical analysis algorithms
- Optimized for educational and research use
- Compatible with standard C99 and later
