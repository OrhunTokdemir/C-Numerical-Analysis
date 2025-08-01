#include "../include/numerical_methods.h"
#include "../include/common.h"
#include "../include/derivative.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Helper function for Newton-Raphson
static double setX1(double (*f)(double), double x0, double h) {
    return x0 - f(x0) / centralDifference(f, x0, h);
}

// Helper function for Secant method
static double setXn(double (*f)(double), double x0, double x1) {
    return x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0));
}

double bisectionMethod(double (*f)(double), double a, double b, double tolerance, int max_iter) {
    if (f(a) * f(b) >= 0) {
        return NAN; // No root in the interval
    }
    
    int step = 0;
    double pn;
    
    while (step < max_iter) {
        pn = (a + b) / 2;
        
        if (fabs(f(pn)) < tolerance || fabs(b - a) < tolerance) {
            return pn;
        }
        
        if (f(a) * f(pn) < 0) {
            b = pn;
        } else {
            a = pn;
        }
        
        step++;
    }

    return pn;
}

double newtonRaphson(double (*f)(double), double x0, double h, double tolerance, int max_iter) {
    double x1 = setX1(f, x0, h);
    int step = 0;
    
    while (fabs(x1 - x0) / fabs(x1) >= tolerance && step < max_iter) {
        x0 = x1;
        x1 = setX1(f, x0, h);
        step++;
    }
    
    if (step >= max_iter) {
        return NAN; // Failed to converge
    }
    
    return x1;
}

double secantMethod(double (*f)(double), double x0, double x1, double tolerance, int max_iter) {
    double x2;
    int step = 0;
    
    while (step < max_iter) {
        if (fabs(f(x1) - f(x0)) < 1e-12) {
            return NAN; // Division by zero
        }
        
        x2 = setXn(f, x0, x1);
        
        if (fabs(f(x2)) < tolerance) {
            return x2;
        }
        
        x0 = x1;
        x1 = x2;
        step++;
    }
    
    return x2;
}

double regulaFalsiMethod(double (*f)(double), double a, double b, double tolerance, int max_iter) {
    if (f(a) * f(b) >= 0) {
        return NAN; // No root in the interval
    }
    
    int step = 0;
    double pn;
    
    while (step < max_iter) {
        if (fabs(f(b) - f(a)) < 1e-12) {
            return NAN; // Division by zero
        }
        
        pn = (a * f(b) - b * f(a)) / (f(b) - f(a)); // Regula Falsi formula
        
        if (fabs(f(pn)) < tolerance || fabs(b - a) < tolerance) {
            return pn;
        }
        
        if (f(a) * f(pn) < 0) {
            b = pn;
        } else {
            a = pn;
        }
        
        step++;
    }
    
    return pn;
}
