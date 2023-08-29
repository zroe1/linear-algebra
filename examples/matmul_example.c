#include "../linalg.h"
#include <stdio.h>

int main() {
  double arr1[2][3] = {
    {1, 7, 8},
    {2, 6, 7}
  };

  double arr2[3][2] = {
    {1, 2},
    {2, 3},
    {5, 2}
  };
  
  Matrix *a = allocate_from_2D_arr(2, 3, arr1);
  Matrix *b = allocate_from_2D_arr(3, 2, arr2);

  putchar('\n');
  print_matmul(a, b);
  putchar('\n');

  Matrix *output = matmul(a, b);
  printf("Resulting matrix of 'matmul' function:\n");
  print_matrix_verbose(output);
  
  free_matrix(a);
  free_matrix(b);
  free_matrix(output);
 
  return 0;
}

