#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "common.h"
#include "derivative.h"

double function(double x) {
    return pow(E,-x)-x;
}
double setX1 (double (*f)(double), double x0, double h) {
    return x0 - f(x0) / centralDifference(f, x0, h);
}

int NewtonRaphson