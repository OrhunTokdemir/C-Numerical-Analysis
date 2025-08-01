#include <stdio.h>
#include <stdlib.h>
#include "./include/common.h"
#include "./include/derivative.h"
#include "./include/secant_method.h"

int main(){
    sekantMethod(f, 1, 1.2, 0.001,200);
    double a= 1.2-(f(1.2)*0.2)/(f(1.2)-f(1));
   
    system("pause");
    return 0;
}

