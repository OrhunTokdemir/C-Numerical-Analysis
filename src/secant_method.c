#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "common.h"
#include "derivative.h"
#include "secant_method.h"

double setXn(double (*f)(double), double x0, double x1) {
    return x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0));
}

int sekantMethod(double (*f)(double), double x0, double x1, double hata, int max_step) {
    double x2;
    int step = 0;
    x2 = setXn(f, x0, x1);
    goster_tekli(x0, f, step++);
    goster_tekli(x1, f, step++);
    do {
        goster_tekli(x2, f, step);
        x0 = x1;
        x1 = x2;
        x2 = setXn(f, x0, x1);
        step++;
    } while ((step < max_step) && fabs(f(x1)) >= hata);
    return 0;
}
