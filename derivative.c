#include<stdio.h>
#include<stdlib.h>
#include<math.h>


double forwardDifference(double (*f)(double), double x, double h) {
    return (f(x + h) - f(x)) / h;
}