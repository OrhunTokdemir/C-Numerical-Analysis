#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "derivative.h"
#include "secant_method.h"

int main(){
    sekantMethod(function, 1, 1.2, 0.001,200);
    double a= 1.2-(function(1.2)*0.2)/(function(1.2)-function(1));
   
    system("pause");
    return 0;
}

