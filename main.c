#include<stdio.h>
#include<stdlib.h>
#include "LinearAlgebra.h"
#include<string.h>

int main(){
    float a[3][3] = {{1,2,3},
                    {4,5,6},
                    {7,8,9}};
    struct LU* lu=LuFactorization((float*)a, 3);
    float* ptr=lu->L;
    float* ptr1=lu->U;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%f ", ptr[i*3+j]);
        }
        printf("\n");
    }
    free(ptr);
    free(ptr1);
    free(lu);  
    return 0;
}