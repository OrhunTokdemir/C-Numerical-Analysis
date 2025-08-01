#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "./include/common.h"
#include "./include/derivative.h"
#include "./include/newton_raphson.h"
double function(double x) {
    return x - pow(2, -x);
}

int main(){
    NewtonRaphson(function, 0, 0.14, 0.0001,30);
    system("pause");
    return 0;
}
