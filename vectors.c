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

static void print_dot_operation(Matrix *A, Matrix *B, double result) {
  unsigned int output_height, output_height_half;
  output_height = A->rows + 2;
  output_height_half = (output_height - 1) / 2;

  for (unsigned int i = 0; i < output_height; i++) {
    print_matrix_row(A, i);
    if (i == output_height_half)
      printf("  .  ");
    else
      printf("     ");

    print_matrix_row(B, i);
    if (i == output_height_half)
      printf("  =  %f\n", result);
    else
      putchar('\n');
  }
}

void print_dot(Matrix *A, Matrix *B) {
  double scalar = dot_product(A, B);
  print_dot_operation(A, B, scalar);
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

static int factorial(int n) {
  int rv = 1;
  while (n > 1) {
    rv *= n--;
  }
  return rv;
}

static double base_to_unsigned_pow(double base, unsigned int power) {
  double rv = 1;

  for (unsigned int i = 0; i < power; i++) {
    rv *= base;
  }

  return rv;
}

static double arccos(double x) {
  double PI = 3.14159265;
  double rv = PI / 2;
  unsigned int n = 9;

  for (unsigned int i = 0; i < n; i++) {
    double numerator1 = factorial(2.0*i);
    double denomenator1 = base_to_unsigned_pow(2, 2*i) * factorial(i) * factorial(i);
    double left = numerator1 / denomenator1;

    double numerator2 = base_to_unsigned_pow(x, 2*i + 1);
    double denomenator2 = 2 * i + 1;
    double right = numerator2 / denomenator2;
    printf("num1: %f, den: %f, left: %f\n",  numerator1, denomenator1, left);
    rv -= left * right;
  }
  return rv;
}

double angle_between_vectors(Matrix *vec1, Matrix *vec2) {
  Matrix *unit_vec1 = allocate_unit_vector(vec1);
  Matrix *unit_vec2 = allocate_unit_vector(vec2);

  double cos_theta = dot_product(unit_vec1, unit_vec2);
  // FREE VECTORS
  return arccos(cos_theta);
}


