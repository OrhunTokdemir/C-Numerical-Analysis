#ifndef DERIVATIVE_H
#define DERIVATIVE_H

// Numerical derivative calculation functions

/**
 * @brief Calculate forward difference derivative approximation
 * @param f Function pointer to the function to differentiate
 * @param x Point at which to calculate the derivative
 * @param h Step size for the difference calculation
 * @return Approximated derivative value
 */
double forwardDifference(double (*f)(double), double x, double h);

/**
 * @brief Calculate backward difference derivative approximation
 * @param f Function pointer to the function to differentiate
 * @param x Point at which to calculate the derivative
 * @param h Step size for the difference calculation
 * @return Approximated derivative value
 */
double backwardDifference(double (*f)(double), double x, double h);

/**
 * @brief Calculate central difference derivative approximation
 * @param f Function pointer to the function to differentiate
 * @param x Point at which to calculate the derivative
 * @param h Step size for the difference calculation
 * @return Approximated derivative value
 */
double centralDifference(double (*f)(double), double x, double h);

#endif // DERIVATIVE_H
