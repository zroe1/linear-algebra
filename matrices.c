#include <stdio.h>
#include <stdlib.h>
#include "linalg.h"

Matrix *allocate_empty(unsigned int rows, unsigned int columns) {
  double **matrix_values = (double **)malloc(sizeof(double *) * rows);
  for (unsigned int i = 0; i < rows; i++) {
    double *current_column = (double *)calloc(columns, sizeof(double));
    matrix_values[i] = current_column;
  }
  
  Matrix *rv = (Matrix *)malloc(sizeof(Matrix));
  rv->rows = rows;
  rv->columns = columns;
  rv->values = matrix_values;
  return rv;
}

Matrix *allocate_from_2D_arr(unsigned int rows, unsigned int columns, 
                             double arr[rows][columns]) {
  double **matrix_values = (double **)malloc(sizeof(double *) * rows);
  for (unsigned int i = 0; i < rows; i++) {
    double *current_column = (double *)malloc(columns * sizeof(double));
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

void free_matrix(Matrix *matrix) {
  for (unsigned int i = 0; i < matrix->rows; i++) {
    free(matrix->values[i]);
  }
  free(matrix->values);
  free(matrix);
}

static int matmul_col_and_row(Matrix *A, Matrix *B, unsigned int A_row, 
                              unsigned int B_col) {
  double rv = 0;
  for (unsigned int i = 0; i < B->rows; i++) {
    rv += A->values[A_row][i] * B->values[i][B_col];
  }
  return rv;
}

Matrix *matmul(Matrix *A, Matrix *B) {
  Matrix *rv = allocate_empty(A->rows, B->columns);
  for (unsigned int current_col = 0; current_col < B->columns; current_col++) {
    for (unsigned int current_row = 0; current_row < A->rows; current_row++) {
      rv->values[current_row][current_col] = matmul_col_and_row(A, B, current_row, current_col);
    }
  }
  return rv;
}

Matrix *matadd(Matrix *A, Matrix *B) {
  Matrix *rv = allocate_empty(A->rows, A->columns);
  for (unsigned int i = 0; i < A->rows; i++) {
    for (unsigned int j = 0; j < B->columns; j++) {
      rv->values[i][j] = A->values[i][j] + B->values[i][j];
    }
  }
  return rv;
}

void matrix_x_scalar(Matrix *matrix, double scalar) {
  for (unsigned int i = 0; i < matrix->rows; i++) {
    for (unsigned int j = 0; j < matrix->columns; j++) {
      matrix->values[i][j] = matrix->values[i][j] * scalar;
    }
  }
}

/*
 * NOTE: The following functions are for printing matrices and operations on
 * matrices. The code is writen so it is possible to print whole matrix 
 * operations over the same lines. If this code is refactored it should preserve that quality.
 */
static unsigned int len_of_num(double num) {
  char num_str[50];
  sprintf(num_str, "%.2f", num);
  
  unsigned int rv = 0;
  while (num_str[rv] != '\0') {
    rv++;
  }
  return rv;
}

/* NOTE: this helper function exists and is written like this becuase it 
makes it easier to print out operations involving multiple matrices */
void print_matrix_row(Matrix *matrix, int row) {
  unsigned int space_per_num = 8;

  if (row == -1) {
    // prints empty row
    for (unsigned int col = 0; col < matrix->columns; col++) {
      for (unsigned int i = 0; i < space_per_num; i++) {
        putchar(' ');
      }
    }
    printf("  ");
    return;
  }

  if (row == 0) { 
    // prints top line
    putchar('/');
    for (unsigned int col = 0; col < matrix->columns; col++) {
      for (unsigned int i = 0; i < space_per_num; i++) {
        putchar(' ');
      }
    }
    putchar('\\');
    return;
  }

  if (row == matrix->rows + 1) {
    // prints bottom line
    putchar('\\');
    for (unsigned int col = 0; col < matrix->columns; col++) {
      for (unsigned int i = 0; i < space_per_num; i++) {
        putchar(' ');
      }
    }
    putchar('/');
    return;
  }

  // print row of values of matrix
  putchar('|');
  for (unsigned int j = 0; j < matrix->columns; j++) {
    unsigned int num_len = len_of_num(matrix->values[row - 1][j]);
    unsigned int left_padding = (space_per_num - num_len) / 2;
    unsigned int right_padding = space_per_num - num_len - left_padding;
    
    while (left_padding-- > 0)
      putchar(' ');
    printf("%.2f", matrix->values[row - 1][j]);
    while (right_padding-- > 0)
      putchar(' ');
  }
  printf("|");
}

void print_matrix(Matrix *matrix) {
  for (int i = 0; i <= matrix->rows + 1; i++) {
    print_matrix_row(matrix, i);
    putchar('\n');
  }
}

void print_matrix_verbose(Matrix *matrix) {
  printf("%d * %d matrix:\n", matrix->rows, matrix->columns);
  print_matrix(matrix);
}

static Matrix *print_operation(Matrix *A, Matrix *B, Matrix *result, char operation) {
  unsigned int output_height, output_height_half;
  unsigned int A_starting_row, A_ending_row;
  unsigned int B_starting_row, B_ending_row;
  unsigned int result_starting_row, result_ending_row;

  if (A->rows > B->rows) {
    output_height = A->rows + 2;
    A_starting_row = 0;
    // NOTE: BELOW SHOULD BE A->rows???
    result_starting_row = (B->rows - result->rows) / 2;
    B_starting_row = (A->rows - B->rows) / 2;
  } else {
    output_height = B->rows + 2;
    A_starting_row = (B->rows - A->rows) / 2;
    result_starting_row = (B->rows - result->rows) / 2;
    B_starting_row = 0;
  }
  
  A_ending_row = A_starting_row + A->rows + 2 - 1;
  B_ending_row = B_starting_row + B->rows + 2 - 1;
  result_ending_row = result_starting_row + result -> rows + 2 - 1;
  output_height_half = (output_height - 1) / 2;

  for (unsigned int i = 0; i < output_height; i++) {
    if (i >= A_starting_row && i <= A_ending_row) {
      print_matrix_row(A, i - A_starting_row);
    } else {
      print_matrix_row(A, -1);
    }

    if (i == output_height_half)
      printf("  %c  ", operation);
    else
      printf("     ");

    if (i >= B_starting_row && i <= B_ending_row) {
      print_matrix_row(B, i - B_starting_row);
    } else {
      print_matrix_row(B, -1);
    }

    if (i == output_height_half)
      printf("  =  ");
    else
      printf("     ");

    if (i >= result_starting_row && i <= result_ending_row) {
      print_matrix_row(result, i - result_starting_row);
    }
    putchar('\n');
  }
  // NOTE DONT RETURN RESULT???
  return result; 
}

void print_matmul(Matrix *A, Matrix *B) {
  Matrix *result = matmul(A, B);
  print_operation(A, B, result, '*');
  free_matrix(result);
}

void print_matadd(Matrix *A, Matrix *B) {
  Matrix *result = matadd(A, B);
  print_operation(A, B, result, '+');
  free_matrix(result);
}


