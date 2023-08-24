#include "matrices.h"

int main() {

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

  Matrix *out = print_matmul(a, b);
  print_matrix_verbose(out);
}
