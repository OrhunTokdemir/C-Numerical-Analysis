#include<stdio.h>
#include<stdlib.h>
#include "LinearAlgebra.h"
#include<string.h>
int main(){
    int* a=(int*)malloc(6*sizeof(int));
    for(int i=0;i<6;i++){
        a[i]=i+1;
    }
    int* b=(int*)malloc(6*sizeof(int));
    memcpy(b, a, 6*sizeof(int)); // Copying array a to b
    for(int i=0;i<6;i++){
        printf("%d ", b[i]);
    }
    
    return 0;
}