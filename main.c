#include<stdio.h>
#include<stdlib.h>
#include "LinearAlgebra.h"
#include<string.h>
int main(){
    float a[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    
    float* ptr=LuFactorization((float*)a, 3);
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%f ", ptr[i*3+j]);
        }
        printf("\n");
    }
    return 0;
}