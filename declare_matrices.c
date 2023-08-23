#include <stdio.h>
#include <stdlib.h>
#include "matrices.h"

/*
typedef struct {
  unsigned int rows;
  unsigned int columns;
  int **values;
} Matrix;
*/
void print_matrix(Matrix *matrix) {
  // prints top line
  putchar('/');
  for (unsigned int i = 0; i < matrix->rows; i++)
    printf("   ");
  printf("\\\n");

  // prints matrix
  for (unsigned int i = 0; i < matrix->rows; i++) {
    putchar('|');
    for (unsigned int j = 0; j < matrix->columns; j++) {
      printf(" %d ", matrix->values[i][j]);
    }
    printf("|\n");
  }

  // prints bottom line
  putchar('\\');
  for (unsigned int i = 0; i < matrix->rows; i++)
    printf("   ");
  printf("/\n");
}

/* Prints the # of rows and cols in a matrix along with it's values */
void print_matrix_verbose(Matrix *matrix) {
  printf("%d * %d matrix:\n", matrix->rows, matrix->columns);
  print_matrix(matrix);
}

/* allocates an empty matrix of size rows * columns */
Matrix *allocate_empty(unsigned int rows, unsigned int columns) {
  int **matrix_values = (int **)malloc(sizeof(int *) * rows);
  for (unsigned int i = 0; i < rows; i++) {
    int *current_column = (int *)calloc(columns, sizeof(int));
    matrix_values[i] = current_column;
  }
  
  Matrix *rv = (Matrix *)malloc(sizeof(Matrix));
  rv->rows = rows;
  rv->columns = columns;
  rv->values = matrix_values;
  return rv;
}

Matrix *allocate_from_2D_arr(unsigned int rows, unsigned int columns, 
                             int arr[rows][columns]) {
  int **matrix_values = (int **)malloc(sizeof(int *) * rows);
  for (unsigned int i = 0; i < rows; i++) {
    int *current_column = (int *)malloc(columns * sizeof(int));
    for (unsigned int j = 0; j < columns; j++) {
      current_column[j] = arr[i][j];
    }
    matrix_values[i] = current_column;
  }
  
  Matrix *rv = (Matrix *)malloc(sizeof(Matrix));
  rv->rows = rows;
  rv->columns = columns;
  rv->values = matrix_values;
  return rv;
  
}
/*
int main() {
  Matrix *v = allocate_empty(3, 3);

  print_matrix(v);
  print_matrix_verbose(v);

  int arr[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };
  Matrix *u = allocate_from_2D_arr(3, 3, arr);
  print_matrix_verbose(u);
}
*/
