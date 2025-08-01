#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "common.h"
#include "derivative.h"
#include "newton_raphson.h"

int main(){
    NewtonRaphson(function, 0, 0.001, 0.0001,30);
    system("pause");
    return 0;
}