/*
Name: Viet Chu
SID:  1692927
CCID: vchu1
CMPUT 275 , Winter 2022
Exercise 5: Matrix
*/
#include <iostream>
#include "matrix.h"
using namespace std;

/*
	Creates a matrix and initializes all elements to init
	
	Arguments:
		row (unsigned int): Number of rows
		col (unsigned int): Number of columns
		init (float): the set value
*/
Matrix::Matrix(unsigned int row, unsigned int col, float init){
	// Input the size of the matrix
	this->row = row;
	this->col = col;
	// Initialize matrix from heap to store rows
	this->vis_matrix = new float*[row];
	// Initialize pointers from heap inside rows to store columns
	for (unsigned int i = 0; i < row; i++){
		vis_matrix[i] = new float[col];
	}
	// Initializing all the elements to the init value spacified by the user
	for (unsigned int i = 0; i < row; i++){
		for (unsigned int j = 0; j < col; j++){
			vis_matrix[i][j] = init;
		}
	}

}

/*
	Creates a matrix and initializes the elements using data in ptr_arr
	Arguments:
		row (unsigned int): Number of row
		col (unsigned int): Number of columns
		arr_ptr (float*): Pointer to the an array
*/


Matrix::Matrix(unsigned int row, unsigned int col, float* arr_ptr){
    // Input the size of the matrix
	this->row = row;
	this->col = col;

	// Initialize matrix from heap to store rows
	this->vis_matrix = new float*[row];

	// Initialize pointers from heap inside rows to store columns
	for (unsigned int i = 0; i < row; i++){
		vis_matrix[i] = new float[col];
	}
	unsigned index = 0;

	// Initializing all the elements to the values spacified by the user
	for (unsigned int i = 0; i < row; i++){
		for (unsigned int j = 0; j < col; j++){
			vis_matrix[i][j] = arr_ptr[index];
			index++;
		}
	}

}

/*
	Overloads the + addition operator 
	 
	Arguments:
		obj (Matrix&): reference to the Matrix instance
	Returns:
		replace (Matrix): The new instance after add the matrixs
*/

Matrix Matrix::operator +( const Matrix& obj) const{
	// To return the Matrix object after performing the assigned operation
	Matrix replace = Matrix(this->row, this->col, 0.0);
	// Since the matrix addition is to add every element to
	// the corresponding elements of the matrix
	for (unsigned int i = 0; i < row; i++){
		for (unsigned int j = 0; j < col; j++){
			replace.vis_matrix[i][j] = this->vis_matrix[i][j] + obj.vis_matrix[i][j];
		}
	}
	return replace;
}
/*
	Overloads the - subtraction operator 
	Arguments:
		obj (Matrix&): reference to the Matrix instance
	Returns:
		replace (Matrix): The new instance after add the matrixs
	
*/
Matrix Matrix::operator -( const Matrix& obj) const{
	// To return the Matrix object after performing the assigned operation
	Matrix replace = Matrix(this->row, this->col, 0.0);
	// Since matrix subtraction is to subract every element to
	// the corresponding elements of the Matrix
	for (unsigned int i = 0; i < row; i++){
		for (unsigned int j = 0; j < col; j++){
			replace.vis_matrix[i][j] = this->vis_matrix[i][j] - obj.vis_matrix[i][j];
		}
	}
	return replace;
}
/*
	Overloads the multiplication operator  
	Arguments:
		obj(Matrix&): reference to the Matrix instance
	Returns:
		replace(Matrix): The new instance after add the matrixs
*/
Matrix Matrix::operator * (const Matrix& obj) const{
	// Create a new matrix
	Matrix replace = Matrix(this->row, obj.col, 0.0);
	// Performing Matrix Multiplication 
	for (unsigned int i = 0; i < this->row; i++){
		for (unsigned int j =0 ; j < obj.col; j++){
			for (unsigned int k = 0; k < this->col; k++){
				replace.vis_matrix[i][j] += (this->vis_matrix[i][k] * obj.vis_matrix[k][j]);
			}
		}
	}
	return replace;
}
/*
	Returns a matrix where all elements are "flipped"
	Returns:
		replace(Matrix): The new object after being flipped
	
*/
Matrix Matrix::operator - () const{
	// Create a new matrix
	Matrix replace = Matrix(row, col, 0.0);
	// Change negative/positive of each element 
	for (unsigned int i = 0; i < row; i++){
		for (unsigned int j = 0; j < col; j++){
			replace.vis_matrix[i][j] = -(this->vis_matrix[i][j]);
		}
	}
	return replace;
}

/*
	Returns a transpose matrix by switching rows and columns (elements)
	Returns:
		replace(Matrix): The new instance after add the matrix
*/
Matrix Matrix::transpose() const{
	// Create a new matrix 
	Matrix replace = Matrix(col, row, 0.0);
	// Exchanging the elements of row to columns and columns to rows
	for (unsigned int i = 0; i < this->col; i++){
		for (unsigned int j = 0; j < this->row; j++){
			replace.vis_matrix[i][j] = this->vis_matrix[j][i];
		}
	}
	return replace;
}
/*
	Returns the float pointer index row of the matrix for both const and not const
	
	Arguments:
		index (unsigned int): The index of the matrix
	Returns:
		float*
	
*/
float* Matrix::operator [] (unsigned int index){
	return this->vis_matrix[index];
}

const float* Matrix::operator [] (unsigned int index) const{
	return this->vis_matrix[index];
}
/*  
    Insertion operator a value to the position [i][j]
*/
istream& operator >> (istream& is, Matrix& obj){
	for (unsigned int i = 0; i < obj.row; i++){
		for (unsigned int j = 0; j < obj.col; j++){
			is >> obj.vis_matrix[i][j];
		}
	}
	return is;
}
/*  
    The extraction operator print elements
*/
ostream& operator << (ostream& os, const Matrix& obj){
	for (unsigned int i = 0; i < obj.row; i++){
		for (unsigned int j = 0; j < obj.col; j++){
			if (j != obj.col-1)
				os << obj.vis_matrix[i][j] << " ";
			else
				os << obj.vis_matrix[i][j];
		}
        if (i != obj.row-1){
            os << endl;
        }
	}
	return os;
}

// Copy Construtor
Matrix::Matrix(const Matrix& cp){
	// Input the size of the matrix
	this->row = cp.row;
	this->col = cp.col;
	// Initialize pointers from heap inside rows to store rows
	this->vis_matrix = new float*[row];
    // Initialize pointers from heap inside rows to store columns
	for (unsigned int i = 0; i < row; i++){
		vis_matrix[i] = new float[col];
	}
    // Copy everything to the new matrix
	for (unsigned int i = 0; i < row; i++){
		for (unsigned int j = 0; j < col; j++){
			this->vis_matrix[i][j] = cp.vis_matrix[i][j];
		}
	}
}

// Destructor
Matrix::~Matrix(){
	for(unsigned int i = 0; i < this->row; i++){
		if (vis_matrix[i] != NULL){
			delete[] vis_matrix[i];
			vis_matrix[i] = NULL;
		}
	}
	if (vis_matrix != NULL){
		delete[] vis_matrix;
		vis_matrix = NULL;
	}
}