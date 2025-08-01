#ifndef GAUSS_SEIDEL_H
#define GAUSS_SEIDEL_H

/**
 * @brief Check if a matrix is diagonally dominant and rearrange if possible
 * @param A Coefficient matrix (row-major order)
 * @param b Right-hand side vector
 * @param n Size of the system (number of variables)
 * @return 1 if matrix is or can be made diagonally dominant, 0 otherwise
 */
int CheckDiagonallyDominant(float* A, float* b, int n);

/**
 * @brief Solve linear system using Gauss-Seidel iterative method
 * @param A Coefficient matrix (row-major order)
 * @param b Right-hand side vector
 * @param xk Initial guess vector (will be updated during iterations)
 * @param n Size of the system (number of variables)
 * @param max_iter Maximum number of iterations
 * @param tolerance Convergence tolerance
 * @return Pointer to solution vector
 */
float* GaussSiedel(float* A, float* b, float* xk, int n, int max_iter, float tolerance);

#endif // GAUSS_SEIDEL_H
