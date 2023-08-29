all: matmul matadd dot

matmul: matmul_example.o matrices.o vectors.o
	clang -o matmul matmul_example.o matrices.o vectors.o

matadd: matadd_example.o matrices.o vectors.o
	clang -o matadd matadd_example.o matrices.o vectors.o

dot: dot.o matrices.o vectors.o
	clang -o dot dot.o matrices.o vectors.o

matrices.o: matrices.c
	clang -c matrices.c

vectors.o: vectors.c
	clang -c vectors.c

matmul_example.o: examples/matmul_example.c
	clang -c examples/matmul_example.c

matadd_example.o: examples/matadd_example.c
	clang -c examples/matadd_example.c

dot.o: examples/dot.c
	clang -c examples/dot.c

clean:
	rm -f *.o main_test matmul matadd dot
