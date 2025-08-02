#ifndef COMMON_H
#define COMMON_H

#define E 2.71828
#define PI_ 3.14159

// Global step counter for all methods
extern int* adim;

// Function prototype for the default function
double f(double x);

// Error checking functions
/**
 * @brief Calculate the absolute error
 * @param p1: current value
 * @param p0: previous value
 * @param hata: tolerance
 * @return: 1 if absolute error is within tolerance, 0 otherwise
 */
int mutlakHata(double p1, double p0, double hata);

/**
 * @brief Calculate the relative error
 * @param p1: current value
 * @param p0: previous value
 * @param hata: tolerance
 * @return: 1 if relative error is within tolerance, 0 otherwise
 */
int bagilHata(double p1, double p0, double hata);

/**
 * @brief Check if there is a root in the interval [a, b]
 * @param a: lower bound
 * @param b: upper bound
 * @param f: function pointer to evaluate
 * @return: 1 if there is a root, 0 otherwise
 */
int checkRoot(double a, double b, double (*f)(double));

// Display functions

/**
 * @brief Display the current step and values
 * @param xn: current value
 * @param f: function pointer to evaluate
 * @param step: current step number
 */
void goster_tekli(double xn, double (*f)(double), int step);

/**
 * @brief Display the current step and values for two points
 * @param x1: first value
 * @param x0: second value
 * @param f: function pointer to evaluate
 * @param step: current step number
 */
void goster_alt(double x1, double x0, double (*f)(double), int step);

/**
 * @brief Display the current step and values for a method
 * @param a: lower bound
 * @param b: upper bound
 * @param fpn: function value at pn
 * @param step: pointer to step counter
 * @param pn: current point
 */
void goster(double a, double b, double fpn, int* step, double pn);

#endif // COMMON_H