#ifndef NEWTON_RAPHSON_H
#define NEWTON_RAPHSON_H

/**
 * @brief Set the next approximation using the center difference formula
 * @param f: function pointer to evaluate
 * @param x0: current approximation
 * @param h: step size
 * @return: next approximation
 */
double setX1(double (*f)(double), double x0, double h);

/**
 * @brief Newton-Raphson method for finding roots of a function
 * @param f: function pointer to evaluate
 * @param x0: initial guess
 * @param h: step size for derivative approximation
 * @param hata: tolerance for convergence
 * @param max_step: maximum number of iterations
 * @return: 0 on success, -1 on failure
 */
int NewtonRaphson(double (*f)(double), double x0, double h, double hata, int max_step);

#endif // NEWTON_RAPHSON_H
