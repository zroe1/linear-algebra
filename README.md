# linear-algebra
Implementation of linear algebra operations in C. <b>Currently in the early stages of development.</b>

## Matrix multiplication
```c
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

print_matmul(a, b);
```
Result:
```
/               \     /          \     /          \
|  1    7    8  |     |  1    2  |     | 55   39  |
|  2    6    7  |  *  |  2    3  |  =  | 49   36  |
\               /     |  5    2  |     \          /
                      \          /
```

## Matrix addition:
```c
int arr1[2][1] = {
  {1},
  {2}
};

int arr2[2][1] = {
  {5},
  {6}
};

Matrix *a = allocate_from_2D_arr(2, 1, arr1);
Matrix *b = allocate_from_2D_arr(2, 1, arr2);

print_matadd(a, b);
```
Result:
```
/     \     /     \     /     \
|  1  |  +  |  5  |  =  |  6  |
|  2  |     |  6  |     |  8  |
\     /     \     /     \     /
```
