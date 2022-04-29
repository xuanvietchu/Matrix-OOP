# Makefile contents here
all: matrix

clean:
	rm *.o 

matrix: matrix.o
	g++ matrix.o -o matrix

matrix.o: matrix.cpp matrix.h
	g++ -c matrix.cpp
