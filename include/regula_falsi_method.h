#ifndef REGULA_FALSI_METHOD_H
#define REGULA_FALSI_METHOD_H


// Regula Falsi method function declaration
// This is the recursive implementation of regula falsi method
/**
 * @brief Regula Falsi method for finding roots of a function
 * @param a: lower bound
 * @param b: upper bound
 * @param f: function pointer to evaluate
 * @param hata: tolerance
 * @return: function recursively if absolute error is bigger than tolerance, 0 when root is found or tolerance is met
 */
int regulaFalsiMethod(double a, double b, double (*f)(double), double hata);

#endif // REGULA_FALSI_METHOD_H
