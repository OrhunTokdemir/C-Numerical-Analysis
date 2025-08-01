#include<stdio.h>
#include<stdlib.h>
#include "common.h"
#include "regula_falsi_method.h"

int main() {
    regulaFalsiMethod(0, 1, 0.00001);
    free(adim); 
    system("pause");
    return 0;
}
