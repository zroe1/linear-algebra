#include <stdio.h>
#include <stdlib.h>
#include "matrices.h"

unsigned int len_of_num(int num) {
  char num_str[14];
  sprintf(num_str, "%d", num);
  
  unsigned int rv = 0;
  while (num_str[rv] != '\0') {
    rv++;
  }
  return rv;
}

void print_matrix(Matrix *matrix) {
  unsigned int space_per_num = 5;

  // prints top line
  putchar('/');
  for (unsigned int col = 0; col < matrix->columns; col++) {
    for (unsigned int i = 0; i < space_per_num; i++) {
      putchar(' ');
    }
  }
  printf("\\\n");

  // prints matrix
  for (unsigned int i = 0; i < matrix->rows; i++) {
    putchar('|');
    for (unsigned int j = 0; j < matrix->columns; j++) {
      unsigned int num_len = len_of_num(matrix->values[i][j]);
      unsigned int left_padding = (space_per_num - num_len) / 2;
      unsigned int right_padding = space_per_num - num_len - left_padding;
      
      while (left_padding-- > 0)
        putchar(' ');

      printf("%d", matrix->values[i][j]);

      while (right_padding-- > 0)
        putchar(' ');
    }
    printf("|\n");
  }

  // prints bottom line
  putchar('\\');
  for (unsigned int col = 0; col < matrix->columns; col++) {
    for (unsigned int i = 0; i < space_per_num; i++) {
      putchar(' ');
    }
  }
  printf("/\n");
}

void print_matrix_verbose(Matrix *matrix) {
  printf("%d * %d matrix:\n", matrix->rows, matrix->columns);
  print_matrix(matrix);
}

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

int matmul_col_and_row(Matrix *A, Matrix *B, unsigned int A_row, 
                        unsigned int B_col) {
  unsigned int rv = 0;
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
