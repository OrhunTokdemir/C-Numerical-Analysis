#define _USE_MATH_DEFINES
#include<math.h>
#include<stdlib.h>
#include<stdio.h>

 



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

float* LuFactorization(float *A, int n){
    float *L=(float *)calloc(n * n, sizeof(float));
    float *U=(float *)calloc(n * n, sizeof(float));
    for(int i=0;i<n;i++){
        L[i*n+i] = 1.0f; 
    }
    memcopy(U, A, n * n * sizeof(float));
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            float lji= U[j*n+i] / U[i*n+i];
            L[j*n+i] = U[j*n+i] / U[i*n+i]; 
            for(int k=i;k<n;k++){
                U[j*n+k] -= lji * U[i*n+k];
            }

        }
    }

}