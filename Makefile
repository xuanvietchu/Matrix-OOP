# Makefile contents here
all: we5_solution

clean:
	rm *.o we5_solution

we5_solution: matrix.o we5_test.o
	g++ matrix.o we5_test.o -o we5_solution 

we5_test.o: we5_test.cpp
	g++ -c we5_test.cpp

matrix.o: matrix.cpp matrix.h
	g++ -c matrix.cpp