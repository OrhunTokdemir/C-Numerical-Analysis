#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

// Matrix operations

/**
 * @brief Add two integer matrices
 * @param ptr0 First matrix (row-major order)
 * @param ptr1 Second matrix (row-major order)
 * @param row0 Number of rows in first matrix
 * @param col0 Number of columns in first matrix
 * @param row1 Number of rows in second matrix
 * @param col1 Number of columns in second matrix
 * @return Pointer to result matrix or NULL on error
 */
int* matrisToplam(int* ptr0, int* ptr1, int row0, int col0, int row1, int col1);

/**
 * @brief Add two float matrices
 * @param ptr0 First matrix (row-major order)
 * @param ptr1 Second matrix (row-major order)
 * @param row0 Number of rows in first matrix
 * @param col0 Number of columns in first matrix
 * @param row1 Number of rows in second matrix
 * @param col1 Number of columns in second matrix
 * @return Pointer to result matrix or NULL on error
 */
float* fmatrisToplam(float* ptr0, float* ptr1, int row0, int col0, int row1, int col1);

/**
 * @brief Subtract two float matrices
 * @param ptr0 First matrix (row-major order)
 * @param ptr1 Second matrix (row-major order)
 * @param row0 Number of rows in first matrix
 * @param col0 Number of columns in first matrix
 * @param row1 Number of rows in second matrix
 * @param col1 Number of columns in second matrix
 * @return Pointer to result matrix or NULL on error
 */
float* fmatrisCikarma(float* ptr0, float* ptr1, int row0, int col0, int row1, int col1);

/**
 * @brief Multiply two integer matrices
 * @param ptr0 First matrix (row-major order)
 * @param ptr1 Second matrix (row-major order)
 * @param row0 Number of rows in first matrix
 * @param col0 Number of columns in first matrix
 * @param row1 Number of rows in second matrix
 * @param col1 Number of columns in second matrix
 * @return Pointer to result matrix or NULL on error
 */
int* matrisCarpim(int* ptr0, int* ptr1, int row0, int col0, int row1, int col1);

/**
 * @brief Multiply two float matrices
 * @param ptr0 First matrix (row-major order)
 * @param ptr1 Second matrix (row-major order)
 * @param row0 Number of rows in first matrix
 * @param col0 Number of columns in first matrix
 * @param row1 Number of rows in second matrix
 * @param col1 Number of columns in second matrix
 * @return Pointer to result matrix or NULL on error
 */
float* fmatrisCarpim(float* ptr0, float* ptr1, int row0, int col0, int row1, int col1);

// LU Decomposition structure
struct LU {
    float* L;
    float* U;
    int n;
};

/**
 * @brief Perform LU decomposition of a matrix
 * @param A Input matrix (row-major order)
 * @param n Size of the square matrix
 * @return Pointer to LU structure containing L and U matrices
 */
struct LU* LuDecomposition(float* A, int n);

/**
 * @brief Free memory allocated for LU decomposition
 * @param lu Pointer to LU structure
 */
void freeLU(struct LU* lu);

/**
 * @brief Solve linear system using LU decomposition
 * @param lu Pointer to LU structure
 * @param b Right-hand side vector
 * @param x Solution vector (output)
 */
void solutionByLu(struct LU* lu, float* b, float* x);

#endif // LINEAR_ALGEBRA_H
