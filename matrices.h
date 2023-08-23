#ifndef MATRICES_H
#define MATRICES_H

typedef struct {
  unsigned int rows;
  unsigned int columns;
  int **values;
} Matrix;

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
                             int arr[rows][columns]);

#endif // MATRICES_H
