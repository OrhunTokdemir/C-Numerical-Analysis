#include "../include/numerical_analysis.h"
#include <stdio.h>
#include <math.h>

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
    
    // Bisection Method Example
    printf("1. Bisection Method Example\n");
    printf("Function: x - 2^(-x) = 0\n");
    printf("Interval: [1, 2]\n");
    double root1 = bisectionMethod(example_function, 1.0, 2.0, 0.0001, 100);
    if (!isnan(root1)) {
        printf("Root found: %.6f\n", root1);
        printf("Verification: f(%.6f) = %.6f\n\n", root1, example_function(root1));
    } else {
        printf("Root not found\n\n");
    }
    
    // Newton-Raphson Method Example
    printf("2. Newton-Raphson Method Example\n");
    printf("Function: e^(-x) - x = 0\n");
    printf("Initial guess: 0.5\n");
    double root2 = newtonRaphson(exponential_function, 0.5, 0.001, 0.0001, 30);
    if (!isnan(root2)) {
        printf("Root found: %.6f\n", root2);
        printf("Verification: f(%.6f) = %.6f\n\n", root2, exponential_function(root2));
    } else {
        printf("Root not found\n\n");
    }
    
    // Secant Method Example
    printf("3. Secant Method Example\n");
    printf("Function: log(x) - cos(x) = 0\n");
    printf("Initial guesses: 1.0, 1.2\n");
    double root3 = secantMethod(log_cos_function, 1.0, 1.2, 0.001, 200);
    if (!isnan(root3)) {
        printf("Root found: %.6f\n", root3);
        printf("Verification: f(%.6f) = %.6f\n\n", root3, log_cos_function(root3));
    } else {
        printf("Root not found\n\n");
    }
    
    // Regula Falsi Method Example
    printf("4. Regula Falsi Method Example\n");
    printf("Function: x - 2^(-x) = 0\n");
    printf("Interval: [0, 1]\n");
    double root4 = regulaFalsiMethod(example_function, 0.0, 1.0, 0.00001, 100);
    if (!isnan(root4)) {
        printf("Root found: %.6f\n", root4);
        printf("Verification: f(%.6f) = %.6f\n\n", root4, example_function(root4));
    } else {
        printf("Root not found\n\n");
    }
    
    // Linear Algebra Example
    printf("5. Linear Algebra Example\n");
    printf("Matrix multiplication:\n");
    
    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int B[3][2] = {{7, 8}, {9, 10}, {11, 12}};
    
    int* result = matrisCarpim((int*)A, (int*)B, 2, 3, 3, 2);
    if (result) {
        printf("A * B =\n");
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                printf("%d ", result[i * 2 + j]);
            }
            printf("\n");
        }
        free(result);
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
        printf("Solution:\n");
        for (int i = 0; i < 3; i++) {
            printf("x[%d] = %.6f\n", i + 1, solution[i]);
        }
        free(solution);
    } else {
        printf("Matrix is not diagonally dominant\n");
    }
    
    return 0;
}

