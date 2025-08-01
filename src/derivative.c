#include "../include/derivative.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Derivatives are cool
// h determines the difference used in difference methods
// *f holds the address of the function to be differentiated

double forwardDifference(double (*f)(double), double x, double h) {
    return (f(x + h) - f(x)) / h;
}

double backwardDifference(double (*f)(double), double x, double h) {
    return (f(x) - f(x - h)) / h;
}

double centralDifference(double (*f)(double), double x, double h) {
    return (f(x + h) - f(x - h)) / (2 * h);
}
