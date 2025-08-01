#ifndef NEWTON_RAPHSON_H
#define NEWTON_RAPHSON_H

// Function declarations for Newton-Raphson method
double function(double x);
double setX1(double (*f)(double), double x0, double h);
int NewtonRaphson(double (*f)(double), double x0, double h, double hata, int max_step);

#endif // NEWTON_RAPHSON_H
