#include<stdio.h>
#include<stdlib.h>
#include "common.h"
#include "bisection_method.h"

int main(){
    
    bisectionMethod(1, 2, 0.0001);
    free(adim);
    system("pause");
    return 0;
}
