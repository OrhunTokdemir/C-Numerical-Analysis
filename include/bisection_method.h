#ifndef BISECTION_METHOD_H
#define BISECTION_METHOD_H


/**
 * @brief Bisection method for finding roots of a function
 * @param a: lower bound
 * @param b: upper bound
 * @param hata: tolerance
 * @return: function recursively if absolute error is bigger than tolerance ,  0 when root is found or tolerance is met
 */
int bisectionMethod(double a, double b, double hata);

// Global step counter for bisection method
extern int* adim;

#endif // BISECTION_METHOD_H
