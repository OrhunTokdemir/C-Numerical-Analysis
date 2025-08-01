#ifndef NUMERICAL_METHODS_H
#define NUMERICAL_METHODS_H

// Root finding methods

/**
 * @brief Find root using bisection method
 * @param f Function pointer to the function
 * @param a Left boundary of the interval
 * @param b Right boundary of the interval
 * @param tolerance Error tolerance
 * @param max_iter Maximum number of iterations
 * @return Root value or NaN if not found
 */
double bisectionMethod(double (*f)(double), double a, double b, double tolerance, int max_iter);

/**
 * @brief Find root using Newton-Raphson method
 * @param f Function pointer to the function
 * @param x0 Initial guess
 * @param h Step size for derivative calculation
 * @param tolerance Error tolerance
 * @param max_iter Maximum number of iterations
 * @return Root value or NaN if not found
 */
double newtonRaphson(double (*f)(double), double x0, double h, double tolerance, int max_iter);

/**
 * @brief Find root using secant method
 * @param f Function pointer to the function
 * @param x0 First initial guess
 * @param x1 Second initial guess
 * @param tolerance Error tolerance
 * @param max_iter Maximum number of iterations
 * @return Root value or NaN if not found
 */
double secantMethod(double (*f)(double), double x0, double x1, double tolerance, int max_iter);

/**
 * @brief Find root using regula falsi method
 * @param f Function pointer to the function
 * @param a Left boundary of the interval
 * @param b Right boundary of the interval
 * @param tolerance Error tolerance
 * @param max_iter Maximum number of iterations
 * @return Root value or NaN if not found
 */
double regulaFalsiMethod(double (*f)(double), double a, double b, double tolerance, int max_iter);

#endif // NUMERICAL_METHODS_H
