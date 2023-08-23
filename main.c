#include "matrices.h"

int main() {
  Matrix *v = allocate_empty(3, 3);
  print_matrix(v);
  print_matrix_verbose(v);
}
