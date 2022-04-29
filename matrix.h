/*
Name: Viet Chu
SID:  1692927
CCID: vchu1
CMPUT 275 , Winter 2022
Exercise 5: Matrix
*/
#ifndef __MATRIX_H__
#define __MATRIX_H__
#include<iostream>
using namespace std;

class Matrix{
public:
    unsigned int row, col;
	float** vis_matrix;
	// Creates a matrix and initializes all the elements to init
	Matrix(unsigned int row, unsigned int col, float init);
	// Creates a matrix and initializes the elements using data stored in a given arr_ptr
	Matrix(unsigned int row, unsigned int col, float* arr_ptr);

	// Overloads the + operator, since we are going to create a new instance,
    // we do not need to modify anything, therefore, the target obj is const
	Matrix operator + (const Matrix& obj)const;

	// Overloads the - operator, since we are going to create a new instance,
    // we do not need to modify anything, therefore, the target obj is const
	Matrix operator - (const Matrix& obj)const;

	// Overloads the multiplication operator, since we are going to create a new instance,
    // we do not need to modify anything, therefore, the target obj is const
	Matrix operator * (const Matrix& obj)const;

	// Overloads a "flip" operator, since we are going to create a new instance,
    // we do not need to modify anything, therefore, the target obj is const
	Matrix operator - ()const;

	// Return a transposed matrix
	Matrix transpose()const;

	// Returns the float pointer index row of the matrix
	float* operator [] (unsigned int index);
	const float* operator [] (unsigned int index)const;

	// Insertion operator a value to the position [i][j]
	friend istream& operator >> (istream& is, Matrix& obj);

	// The extraction operator print elements
	friend ostream& operator << (ostream& os,const Matrix& obj);

	// Return a copy of the targeted matrix
	Matrix(const Matrix& cp);

	// Free memory when a matrix object goes out of scope
	~Matrix();
};

#endif