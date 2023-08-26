# Linear algebra in C
Implementation of linear algebra operations in C. <b>Currently in the early stages of development.</b>

## Matrix multiplication
```c
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

print_matmul(a, b);
```
Result:
```
/                        \     /                \     /                \
|  1.00    7.00    8.00  |     |  1.00    2.00  |     | 55.00   39.00  |
|  2.00    6.00    7.00  |  *  |  2.00    3.00  |  =  | 49.00   36.00  |
\                        /     |  5.00    2.00  |     \                /
                               \                /     
```

## Matrix addition:
```c
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

print_matadd(a, b);
```
Result:
```
/        \     /        \     /        \
|  1.00  |  +  |  5.00  |  =  |  6.00  |
|  2.00  |     |  6.00  |     |  8.00  |
\        /     \        /     \        /
```
