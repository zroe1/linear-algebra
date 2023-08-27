#include <stdio.h>
#include <stdlib.h>
#include "linalg.h"

static double square_root(double num) {
  double guess = num / 2;
  double accuracy = 0.00001;

  while (guess * guess - num > accuracy) {
    guess = 0.5 * (guess + (num / guess));
  }

  return guess;
}

double norm(Matrix *vector) {
  double rv = 0;

  for (unsigned int i = 0; i < vector->rows; i++) {
    for (unsigned int j = 0; j < vector->columns; j++) {
      rv += vector->values[i][j] * vector->values[i][j];
    }
  }

  return square_root(rv);
}

/* Assumes the the vectors are both rows or both columns */
double dot_product(Matrix *vec1, Matrix *vec2) {
  double rv = 0;

  for (unsigned int i = 0; i < vec1->rows; i++) {
    for (unsigned int j = 0; j < vec1->columns; j++) {
      rv += vec1->values[i][j] * vec2->values[i][j];
    }
  }

  return rv;
}

Matrix *allocate_unit_vector(Matrix *vector) {
  Matrix *unit_vector = allocate_empty(vector->rows, vector->columns);
  unit_vector->rows = vector->rows;
  unit_vector->columns = vector->columns;

  double vector_length = norm(vector);

  for (unsigned int i = 0; i < vector->rows; i++) {
    for (unsigned int j = 0; j < vector->columns; j++) {
      unit_vector->values[i][j] = vector->values[i][j] / vector_length;
    }
  }

  return unit_vector;
}

int main() {
  double arr1[3][1] = {
    {1}, 
    {7},
    {8}
  };
  
  double arr2[3][1] = {
    {1},
    {2},
    {1}
  };

  Matrix *a = allocate_from_2D_arr(3, 1, arr1);
  Matrix *b = allocate_from_2D_arr(3, 1, arr2);
  
  double len = norm(a);
  printf("Length of vector a: %f\n", len);

  double dot = dot_product(a, b);
  printf("Dot product: %f\n", dot);

  Matrix *unit_vec = allocate_unit_vector(b);
  print_matrix_verbose(unit_vec);

  matrix_x_scalar(unit_vec, 10);
  print_matrix_verbose(unit_vec);
}
