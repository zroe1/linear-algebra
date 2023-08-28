#include "../linalg.h"
#include <stdio.h>

int main() {
  double arr1[2][1] = {
    {1},
    {2}
  };

  double arr2[2][1] = {
    {5},
    {6}
  };

  Matrix *a = allocate_from_2D_arr(2, 1, arr1);
  Matrix *b = allocate_from_2D_arr(2, 1, arr2);

  putchar('\n');
  print_matadd(a, b);
  putchar('\n');

  Matrix *output = matadd(a, b);
  printf("Resulting matrix of 'matadd' function:\n");
  print_matrix_verbose(output);

  free_matrix(a);
  free_matrix(b);
  free_matrix(output);

  return 0;
}
