#include "../linalg.h"
#include <stdio.h>

int main() {
  double arr1[3][1] = {
    {1},
    {2},
    {3}
  };

  double arr2[3][1] = {
    {4},
    {5},
    {6}
  };

  Matrix *a = allocate_from_2D_arr(3, 1, arr1);
  Matrix *b = allocate_from_2D_arr(3, 1, arr2);
  
  print_dot(a, b);
  putchar('\n');
  
  free_matrix(a);
  free_matrix(b);

  double arr3[1][3] = {
    {1, 2, 3}
  };

  double arr4[1][3] = {
    {4, 5, 6}
  };

  Matrix *c = allocate_from_2D_arr(1, 3, arr3);
  Matrix *d = allocate_from_2D_arr(1, 3, arr4);

  print_dot(c, d);
  free_matrix(c);
  free_matrix(d);
}
