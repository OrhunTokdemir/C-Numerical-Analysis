#include <stdio.h>
#include "common.h"

int main() {
    printf("Testing Numerical Analysis Library\n");
    printf("===================================\n");
    
    // Test the default function f(x) = x - 2^(-x)
    double x = 1.5;
    printf("Testing f(%f) = %f\n", x, f(x));
    
    // Test display function
    goster_tekli(x, f, 1);
    
    // Test root checking
    int has_root = checkRoot(0.0, 1.0);
    printf("\nRoot exists between 0 and 1: %s\n", has_root ? "Yes" : "No");
    
    // Test error functions
    double p0 = 1.0, p1 = 1.1, tolerance = 0.01;
    int abs_error = mutlakHata(p1, p0, tolerance);
    printf("Absolute error test: %s\n", abs_error ? "Within tolerance" : "Exceeds tolerance");
    
    int rel_error = bagilHata(p1, p0, tolerance);
    printf("Relative error test: %s\n", rel_error ? "Within tolerance" : "Exceeds tolerance");
    
    return 0;
}
