#include "../include/linear_algebra.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int* matrisToplam(int* ptr0, int* ptr1, int row0, int col0, int row1, int col1) {
    if (col0 != col1 || row0 != row1) {
        fprintf(stderr, "Error: Matrices must have the same dimensions for addition.\n");
        return NULL; // Matrices must have the same dimensions
    }
    int* ptrsum = (int*)malloc(row0 * col0 * sizeof(int));
    for (int i = 0; i < row0; i++) {
        for (int j = 0; j < col0; j++) {
            ptrsum[i * col0 + j] = ptr0[i * col0 + j] + ptr1[i * col1 + j];
        }
    }
    return ptrsum;
}

float* fmatrisToplam(float* ptr0, float* ptr1, int row0, int col0, int row1, int col1) {
    if (col0 != col1 || row0 != row1) {
        fprintf(stderr, "Error: Matrices must have the same dimensions for addition.\n");
        return NULL; // Matrices must have the same dimensions
    }
    float* ptrsum = (float*)malloc(row0 * col0 * sizeof(float));
    for (int i = 0; i < row0; i++) {
        for (int j = 0; j < col0; j++) {
            ptrsum[i * col0 + j] = ptr0[i * col0 + j] + ptr1[i * col1 + j];
        }
    }
    return ptrsum;
}

float* fmatrisCikarma(float* ptr0, float* ptr1, int row0, int col0, int row1, int col1) {
    if (col0 != col1 || row0 != row1) {
        fprintf(stderr, "Error: Matrices must have the same dimensions for subtraction.\n");
        return NULL; // Matrices must have the same dimensions
    }
    float* ptrsum = (float*)malloc(row0 * col0 * sizeof(float));
    for (int i = 0; i < row0; i++) {
        for (int j = 0; j < col0; j++) {
            ptrsum[i * col0 + j] = ptr0[i * col0 + j] - ptr1[i * col1 + j];
        }
    }
    return ptrsum;
}

int* matrisCarpim(int* ptr0, int* ptr1, int row0, int col0, int row1, int col1) {
    if (col0 != row1) {
        fprintf(stderr, "Error: Number of columns in first matrix must equal number of rows in second matrix for multiplication.\n");
        return NULL; // Matrices must be compatible for multiplication
    }
    int* ptrprod = (int*)malloc(row0 * col1 * sizeof(int));
    for (int i = 0; i < row0; i++) {
        for (int j = 0; j < col1; j++) {
            ptrprod[i * col1 + j] = 0; // Initialize the product element
            for (int k = 0; k < col0; k++) {
                ptrprod[i * col1 + j] += ptr0[i * col0 + k] * ptr1[k * col1 + j];
            }
        }
    }
    return ptrprod;
}

float* fmatrisCarpim(float* ptr0, float* ptr1, int row0, int col0, int row1, int col1) {
    if (col0 != row1) {
        fprintf(stderr, "Error: Number of columns in first matrix must equal number of rows in second matrix for multiplication.\n");
        return NULL; // Matrices must be compatible for multiplication
    }
    // Size of the result matrix is row0 x col1
    float* ptrprod = (float*)malloc(row0 * col1 * sizeof(float));
    for (int i = 0; i < row0; i++) {
        for (int j = 0; j < col1; j++) {
            ptrprod[i * col1 + j] = 0.0f; // Initialize the product element
            for (int k = 0; k < col0; k++) {
                ptrprod[i * col1 + j] += ptr0[i * col0 + k] * ptr1[k * col1 + j];
            }
        }
    }
    return ptrprod;
}

struct LU* LuDecomposition(float* A, int n) {
    float* L = (float*)calloc(n * n, sizeof(float));
    float* U = (float*)calloc(n * n, sizeof(float));
    struct LU* lu = (struct LU*)malloc(sizeof(struct LU));
    
    for (int i = 0; i < n; i++) {
        L[i * n + i] = 1.0f;
    }
    memcpy(U, A, n * n * sizeof(float));
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (fabs(U[i * n + i]) < 1e-12) {
                // Pivot is too small, decomposition failed
                free(L);
                free(U);
                free(lu);
                return NULL;
            }
            
            float lji = U[j * n + i] / U[i * n + i];
            L[j * n + i] = lji;
            for (int k = i; k < n; k++) {
                U[j * n + k] -= lji * U[i * n + k];
            }
        }
    }
    lu->n = n;
    lu->L = L;
    lu->U = U;
    
    return lu;
}

void freeLU(struct LU* lu) {
    if (lu) {
        free(lu->L);
        free(lu->U);
        free(lu);
    }
}

void solutionByLu(struct LU* lu, float* b, float* x) {
    int n = lu->n;
    float* L = lu->L;
    float* U = lu->U;
    float* y = (float*)malloc(n * sizeof(float));
    
    // Forward substitution to solve Ly = b
    y[0] = b[0] / L[0];
    for (int i = 1; i < n; i++) {
        y[i] = b[i];
        for (int j = 0; j < i; j++) {
            y[i] -= L[i * n + j] * y[j];
        }
        y[i] /= L[i * n + i];
    }
    
    // Backward substitution to solve Ux = y
    x[n - 1] = y[n - 1] / U[(n - 1) * n + (n - 1)];
    for (int i = n - 2; i >= 0; i--) {
        x[i] = y[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= (U[i * n + j] * x[j]) / U[i * n + i];
        }
    }
    free(y);
}
