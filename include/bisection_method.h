#ifndef BISECTION_METHOD_H
#define BISECTION_METHOD_H


/**
 * @brief Bisection method for finding roots of a function
 * @param a: lower bound
 * @param b: upper bound
 * @param f: function pointer to the function for which we are trying to find a root
 * @param hata: tolerance
 * @return: function recursively if absolute error is bigger than tolerance ,  0 when root is found or tolerance is met
 */
int bisectionMethod(double a, double b, double (*f)(double), double hata);

#endif // BISECTION_METHOD_H
