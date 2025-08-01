#include<stdio.h>
#include<stdlib.h>
#include "./include/linear_algebra.h"
#include<string.h>

int main(){
    float a[3][3] = {{1,2,3},
                    {2,5,2},
                    {3,1,5}};
    struct LU* lu=LuDecomposition((float*)a, 3);
    float* ptr=lu->L;
    float* ptr1=lu->U;
    for(int i=0; i<3; i++){
        printf("|");
        for(int j=0; j<3; j++){
            printf("%5.2f ", ptr[i*3+j]);
        }
        printf("|\n");
    }
    printf("\n");
    for(int i=0; i<3; i++){
        printf("|");
        for(int j=0; j<3; j++){
            printf("%5.2f ", ptr1[i*3+j]);
        }
        printf("|\n");
    }
    float* x=(float*)malloc(3 * sizeof(float));
    printf("\n");
    solutionByLu(lu, (float[]){14,18,20}, x);

    for(int i=0; i<3; i++){
        printf("%5.2f ", x[i]);
    }

    
} 