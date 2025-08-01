#include "../include/numerical_analysis.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Example function: x - 2^(-x) = 0
double example_function(double x) {
    return x - pow(2, -x);
}

// Example function: e^(-x) - x = 0
double exponential_function(double x) {
    return exp(-x) - x;
}

// Example function: log(x) - cos(x) = 0
double log_cos_function(double x) {
    return log(x) - cos(x);
}

int main() {
    printf("=== Numerical Analysis Library Examples ===\n\n");
    
    // Note: Based on your function signatures, these are demonstrations
    // The actual functions take different parameters than expected
    
    printf("1. Bisection Method Example\n");
    printf("Function: x - 2^(-x) = 0\n");
    printf("Note: The bisectionMethod function takes (a, b, hata) parameters\n");
    printf("It uses a global function, not a function pointer\n\n");
    
    printf("2. Newton-Raphson Method Example\n");
    printf("Function: e^(-x) - x = 0\n");
    printf("Note: The NewtonRaphson function takes (f, x0, h, hata, max_step) parameters\n");
    int result = NewtonRaphson(exponential_function, 0.5, 0.001, 0.0001, 30);
    if (result == 0) {
        printf("Newton-Raphson completed successfully\n\n");
    } else {
        printf("Newton-Raphson failed\n\n");
    }
    
    printf("3. Secant Method Example\n");
    printf("Function: log(x) - cos(x) = 0\n");
    printf("Note: The sekantMethod function takes (f, x0, x1, hata, max_step) parameters\n");
    int result2 = sekantMethod(log_cos_function, 1.0, 1.2, 0.001, 200);
    if (result2 == 0) {
        printf("Secant method completed successfully\n\n");
    } else {
        printf("Secant method failed\n\n");
    }
    
    printf("4. Regula Falsi Method Example\n");
    printf("Function: x - 2^(-x) = 0\n");
    printf("Note: The regulaFalsiMethod function takes (a, b, hata) parameters\n");
    printf("It uses a global function, not a function pointer\n\n");
    
    // Linear Algebra Example
    printf("5. Linear Algebra Example\n");
    printf("Matrix multiplication:\n");
    
    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int B[3][2] = {{7, 8}, {9, 10}, {11, 12}};
    
    int* result3 = matrisCarpim((int*)A, (int*)B, 2, 3, 3, 2);
    if (result3) {
        printf("A * B =\n");
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                printf("%d ", result3[i * 2 + j]);
            }
            printf("\n");
        }
        free(result3);
    }
    printf("\n");
    
    // Gauss-Seidel Example
    printf("6. Gauss-Seidel Method Example\n");
    printf("System: 15x1 + 5x2 - 5x3 = 29\n");
    printf("        -5x1 + 5x2 + 15x3 = -7\n");
    printf("        5x1 + 20x2 + 10x3 = -3\n");
    
    float A_gs[3][3] = {
        {15.0f, 5.0f, -5.0f},
        {-5.0f, 5.0f, 15.0f},
        {5.0f, 20.0f, 10.0f}
    };
    float b_gs[3] = {29.0f, -7.0f, -3.0f};
    float x0[3] = {2.0f, -1.0f, 1.0f};
    
    if (CheckDiagonallyDominant((float*)A_gs, b_gs, 3)) {
        float* solution = GaussSiedel((float*)A_gs, b_gs, x0, 3, 10, 0.01f);
        if (solution) {
            printf("Solution:\n");
            for (int i = 0; i < 3; i++) {
                printf("x[%d] = %.6f\n", i + 1, solution[i]);
            }
            free(solution);
        }
    } else {
        printf("Matrix is not diagonally dominant\n");
    }
    
    return 0;
}
