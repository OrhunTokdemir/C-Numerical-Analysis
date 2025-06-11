#include<stdio.h>
#include<stdlib.h>
#include "LinearAlgebra.h"

int main(){
    int mat1[2][3] = {{1, 2, 3},{4, 5, 6}};
    int mat2[3][2] = {{7, 8}, {9, 10}, {11, 12}};
    
    
    int *ptr1 = (int *)mat1;
    int *ptr2 = (int *)mat2;
    int *result = matrisCarpim(ptr1, ptr2, 2, 3, 3, 2);
    
    
    if (result != NULL) {
        printf("Product of matrices:\n");
        for (int i = 0; i < 2; i++) {
            printf("|");
            for (int j = 0; j < 2; j++) {
                printf("%3d ", result[i * 2 + j]);
            }
            printf("|\n");
        }
        free(result); 
    }

    return 0;
}