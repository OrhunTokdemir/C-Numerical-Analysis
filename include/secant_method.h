#ifndef SECANT_METHOD_H
#define SECANT_METHOD_H

// Function declarations for secant method
double setXn(double (*f)(double), double x0, double x1);
int sekantMethod(double (*f)(double), double x0, double x1, double hata, int max_step);

#endif // SECANT_METHOD_H
