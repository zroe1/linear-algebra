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

int main() {
  double arr1[1][3] = {
    {1, 7, 8}
  };

  Matrix *a = allocate_from_2D_arr(1, 3, arr1);

  
  double len = norm(a);
  printf("Length of vector a: %f\n", len);
}
