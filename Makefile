all: matmul_example matadd_example

matmul_example: matmul_example.o matrices.o
	clang -o matmul_example matmul_example.o matrices.o

matadd_example: matadd_example.o matrices.o
	clang -o matadd_example matadd_example.o matrices.o

matrices.o: matrices.c
	clang -c matrices.c

matmul_example.o: examples/matmul_example.c
	clang -c examples/matmul_example.c

matadd_example.o: examples/matadd_example.c
	clang -c examples/matadd_example.c

clean:
	rm -f *.o main_test matmul_example matadd_example
