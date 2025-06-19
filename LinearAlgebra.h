#define _USE_MATH_DEFINES
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int * matrisToplam(int*ptr0 ,int* ptr1, int row0, int col0, int row1, int col1){
    if(col0!=col1 || row0!=row1){
        fprintf(stderr, "Error: Matrices must have the same dimensions for addition.\n");
        return NULL; // Matrices must have the same dimensions
    }
    int *ptrsum = (int *)malloc(row0 * col0 * sizeof(int));
    for(int i=0; i<row0; i++){
        for(int j=0; j<col0; j++){
            ptrsum[i*col0+j] = ptr0[i*col0+j]+ptr1[i*col1+j];
        }
    }
    return ptrsum;
}

float* fmatrisToplam(float *ptr0,float* ptr1, int row0, int col0, int row1, int col1){
    if(col0!=col1 || row0!=row1){
        fprintf(stderr, "Error: Matrices must have the same dimensions for addition.\n");
        return NULL; // Matrices must have the same dimensions
    }
    float *ptrsum = (float *)malloc(row0 * col0 * sizeof(float));
    for(int i=0; i<row0; i++){
        for(int j=0; j<col0; j++){
            ptrsum[i*col0+j] = ptr0[i*col0+j]+ptr1[i*col1+j];
        }
    }
    return ptrsum;
}

float* fmatrisCikarma(float *ptr0,float* ptr1, int row0, int col0, int row1, int col1){
    if(col0!=col1 || row0!=row1){
        fprintf(stderr, "Error: Matrices must have the same dimensions for addition.\n");
        return NULL; // Matrices must have the same dimensions
    }
    float *ptrsum = (float *)malloc(row0 * col0 * sizeof(float));
    for(int i=0; i<row0; i++){
        for(int j=0; j<col0; j++){
            ptrsum[i*col0+j] = ptr0[i*col0+j]-ptr1[i*col1+j];
        }
    }
    return ptrsum;
}

int* matrisCarpim(int *ptr0, int *ptr1, int row0, int col0, int row1, int col1) {
    if (col0 != row1) {
        fprintf(stderr, "Error: Number of columns in first matrix must equal number of rows in second matrix for multiplication.\n");
        return NULL; // Matrices must be compatible for multiplication
    }
    int *ptrprod = (int *)malloc(row0 * col1 * sizeof(int));
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

float* fmatrisCarpim(float *ptr0, float *ptr1, int row0, int col0, int row1, int col1) {
    if (col0 != row1) {
        fprintf(stderr, "Error: Number of columns in first matrix must equal number of rows in second matrix for multiplication.\n");
        return NULL; // Matrices must be compatible for multiplication
    }
    //size of the result matrice is row0 x col1
    float *ptrprod = (float *)malloc(row0 * col1 * sizeof(float));
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
//psuedo code for LU factorization
//1.	Initialize  L  to an identity matrix,  I  of dimension  n×n  and  U=A.
//2.	For  i=1,…,n  do Step 3
//3.  For  j=i+1,…,n do Steps 4-5
//4.	Set  lji=uji/uii 
//5.	Perform  Uj=(Uj−ljiUi)(where  Ui,Uj represent the  i and  j rows of the matrix  U, respectively)
// I got this psuedo code from "https://johnfoster.pge.utexas.edu/numerical-methods-book/LinearAlgebra_LU.html#Psuedocode-for-a-simple-$\mathbf{LU}$-factorization"
struct LU {
    float *L;
    float *U;
    int n;
};

struct LU* LuDecomposition(float *A, int n){
    float *L=(float *)calloc(n * n, sizeof(float));
    float *U=(float *)calloc(n * n, sizeof(float));
    struct LU* lu=(struct LU*)malloc(sizeof(struct LU));
    for(int i=0;i<n;i++){
        L[i*n+i] = 1.0f; 
    }
    memcpy(U, A, n * n * sizeof(float));
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            float lji= U[j*n+i] / U[i*n+i];
            L[j*n+i] = U[j*n+i] / U[i*n+i]; 
            for(int k=i;k<n;k++){
                U[j*n+k] -= lji * U[i*n+k];
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

void SolutionByLu(struct LU* lu, float* b, float* x) {
    int n = lu->n;
    float* L = lu->L;
    float* U = lu->U;
    float* y = (float*)malloc(n * sizeof(float));
    
    // Forward substitution to solve Ly = b
    y[0] = b[0] / L[0];
    for(int i=1; i<n; i++){
        y[i] = b[i];
        for(int j=0; j<i; j++){
            y[i] -= L[i*n+j] * y[j];
        }
        y[i] /= L[i*n+i];
    }
    // Backward substitution to solve Ux = y
    x[n-1] = y[n-1] / U[(n-1)*n + (n-1)];
    for(int i=n-2;i>=0;i--){
        x[i] = y[i];
        for(int j=i+1;j<n;j++){
            x[i] -= (U[i*n+j] * x[j]) / U[i*n+i];
        }
    }
    free(y);

    freeLU(lu);
}

