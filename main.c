#include "matrices.h"

int main() {
  //Matrix *v = allocate_empty(3, 3);
  //print_matrix(v);
  //print_matrix_verbose(v);

  int arr1[2][3] = {
    {1, 7, 8},
    {2, 6, 7}
  };

  int arr2[3][2] = {
    {1, 2},
    {2, 3},
    {5, 2}
  };

  Matrix *a = allocate_from_2D_arr(2, 3, arr1);
  Matrix *b = allocate_from_2D_arr(3, 2, arr2);

  print_matrix_verbose(a);
  print_matrix_verbose(b);

  Matrix *out = matmul(a, b);
  print_matrix_verbose(out);
}
