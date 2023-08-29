#ifndef MATRICES_H
#define MATRICES_H

typedef struct {
  unsigned int rows;
  unsigned int columns;
  double **values;
} Matrix;

void print_matrix_row(Matrix *matrix, int row);

/**
 * Prints a matrix to standard output.
 * 
 * @param matrix The matrix to be printed.
 */
void print_matrix(Matrix *matrix);

/**
 * Prints a matrix and it's dimensions to standard output.
 * 
 * @param matrix The matrix to be printed.
 */
void print_matrix_verbose(Matrix *matrix);

/**
 * Allocates a matrix and it's values (initialized to 0) to the heap.
 * 
 * @param rows The number of rows in the matrix.
 * @param columns The number of columns in the matrix.
 * @return The allocated Matrix struct
 */
Matrix *allocate_empty(unsigned int rows, unsigned int columns);

/**
 * Allocates a matrix struct to the heap using the values of the 2D array 
 * passed to the function.
 * 
 * @param rows The number of rows in the matrix.
 * @param columns The number of columns in the matrix.
 * @param arr[rows][columns] The 2D array where the matrix gets it's values
 * @return The allocated Matrix struct
 */
Matrix *allocate_from_2D_arr(unsigned int rows, unsigned int columns,
                             double arr[rows][columns]);

/**
 * Frees an allocated matrix and the values associated with it.
 * 
 * @param matrix The matrix to be freed
 */
void free_matrix(Matrix *matrix);

/**
 * Preforms matrix multiplication on 2 matrices and returns the result as a
 * freshly allocated matrix.
 * 
 * @param A The first matrix to be multiplied.
 * @param B The second matrix to be multiplied.
 * @return The result of the matrix multiplication.
 */
Matrix *matmul(Matrix *A, Matrix *B);

/**
 * Multiplies each number in a matrix by a scalar.
 * 
 * @param matrix The matrix to be multiplied.
 * @param scalar The scalar for the matrix to be multiplied by
 */
void matrix_x_scalar(Matrix *matrix, double scalar);

/**
 * Prints the matrix multiplication of 2 matrices.
 * 
 * @param A The first matrix to be multiplied.
 * @param B The second matrix to be multiplied.
 */
void print_matmul(Matrix *A, Matrix *B);

/**
 * Preforms matrix addition on 2 matrices and returns the result as a
 * freshly allocated matrix.
 * 
 * @param A The first matrix to be added.
 * @param B The second matrix to be added.
 * @return The result of the matrix addition.
 */
Matrix *matadd(Matrix *A, Matrix *B);

/**
 * Prints the matrix addition of 2 matrices.
 * 
 * @param A The first matrix to be added.
 * @param B The second matrix to be added.
 */
void print_matadd(Matrix *A, Matrix *B);


/**
 * Calculates the length of a vector.
 * 
 * @param vector A size 1 x n or n x 1 matrix to represent a vector
 * @return The length of the input vector
 */
double norm(Matrix *vector);

/**
 * Calculates the dot product of two vectors and returns the answer as a
 * scalar.
 * 
 * @param vec1 A size 1 x n or n x 1 matrix to represent a vector
 * @param vec2 A size 1 x n or n x 1 matrix to represent a vector
 * @return The dot product of the input vectors
 */
double dot_product(Matrix *vec1, Matrix *vec2);

void print_dot(Matrix *A, Matrix *B);

/**
 * Allocates and returns the unit vector for the vector passed into the 
 * function
 * 
 * @param vector A size 1 x n or n x 1 matrix to represent a vector
 * @return A size 1 x n or n x 1 Matrix to represent the unit vector of the
 * vector passed into the function.
 */
Matrix *allocate_unit_vector(Matrix *vector);


/**
 * Calculates the angle between vectors.
 * 
 * @param vec1 A size 1 x n or n x 1 matrix to represent a vector
 * @param vec2 A size 1 x n or n x 1 matrix to represent a vector
 * @return The angle between the vectors as a scalar.
 */
double angle_between_vectors(Matrix *vec1, Matrix *vec2);

#endif // MATRICES_H
