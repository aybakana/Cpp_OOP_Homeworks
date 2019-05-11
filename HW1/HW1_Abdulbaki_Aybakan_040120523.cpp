/*
                   								HOMEWORK 1
	@NAME         	:           ABDULBAKÝ AYBAKAN
	@SCHOOL NUMBER	:  			040120523

*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <array>
#include <sstream>
#include <string>
#include <stdio.h>

using namespace std;

class Matrix{
	private:
		bool test_stochastic(void);
	public:
		int rows;
		int cols;
		float data[10][10];
		Matrix(int,int);                                // Parametered Constructor
		Matrix();                                       // Default Constructor
		Matrix(float data[10][10],int rows,int cols);   // Parametered Constructor
		void print(void);								// Print function for a Matrix

		Matrix operator+(const Matrix &);               //Overloading of plus(+) operator
		Matrix operator+(float scalar_value);			//Overloading of plus(+) operator with a scalar value
		void operator++(void);							//Overloading of ++ operator
		void operator+=(const Matrix &);				//Overloading of += operator with a Matrix

};
void Matrix::print(void){  								// Print function for a Matrix
	for (int i=0; i<rows; i++){
		cout << endl;
		for (int j=0; j<cols; j++){
				cout << this->data[i][j]<<" ";
		}
	}
	if(this->test_stochastic()){
		cout <<endl<<endl<< "THIS MATRIX IS STOCHASTIC" <<endl;
	}
	else cout <<endl<<endl<< "THIS MATRIX IS NOT STOCHASTIC" <<endl;
	cout << "===============================" << endl;
}

bool Matrix::test_stochastic(){       					//  Test of stochastic function
	if(this->cols==this->rows)
		return true;
	else return false;
}

Matrix::Matrix(int r, int c){    						// Parametered constructor
	this->rows=r;
	this->cols=c;
	this->data[rows][cols];

	for (int i=0; i<rows; i++){
		for (int j=0; j<cols; j++){
				this->data[i][j] = 0;
		}
	}
}

Matrix::Matrix(){   									// Default constructor
	this->rows=0;
	this->cols=0;
}
Matrix::Matrix(float datain[10][10],int row,int col){  	// Parametered constructor
	this->rows=row;
	this->cols=col;
	for (int i=0; i<rows; i++){
		for (int j=0; j<cols; j++){
				this->data[i][j] = datain[i][j];
		}
	}
}


Matrix Matrix::operator+(const Matrix & m){              // Addition with a matrix
	int r=this->rows;
	int c=this->cols;
	Matrix T(r,c);
	if((this->rows==m.rows)&(this->cols==m.cols)){

		for(int j=0;j<this->rows;j++){
			for (int i=0;i<this->cols;i++){
				 T.data[i][j]=this->data[i][j]+m.data[i][j];
			}
		}
	}
	else
		cout << "ADDITION IS NOT POSSIBLE!"	;
	return T;
}

Matrix Matrix::operator+(float scalar_value){     //  Addition with a scalar value
	Matrix S(this->rows,this->cols);
	for(int j=0;j<this->rows;j++){
			for (int i=0;i<this->cols;i++){
				 S.data[i][j]=this->data[i][j]+scalar_value;
			}
	}
	return S;
}

void Matrix::operator++(){                  		// Increment operator overloading

	for(int j=0;j<this->rows;j++){
			for (int i=0;i<this->cols;i++){
				 this->data[i][j]=this->data[i][j]+1;
			}
	}
}



void Matrix::operator+=(const Matrix & m){
	for(int j=0;j<m.rows;j++){
			for (int i=0;i<m.cols;i++){
				 this->data[i][j]=this->data[i][j]+m.data[i][j];
			}
	}

}

int main(){
	string lineA;
	ifstream fileIN;
	int k=0;
	int colA;
	Matrix Mat[20];

	fileIN.open("MATRICES.txt");

	int rowA=0;
	while(!fileIN.eof()){
		getline(fileIN,lineA);
		stringstream streamA(lineA);
		streamA>>Mat[k].rows;
		streamA>>Mat[k].cols;
		rowA=0;
		while(getline(fileIN,lineA)){
			stringstream streamA(lineA);
			colA=0;
			float x;
			while(streamA >> x){
				Mat[k].data[rowA][colA]=x;
				colA++;
			}
			rowA++;
			if (rowA==Mat[k].rows){       // BREAK point
				k++;
				break;
			}
		}

	}



	Matrix Result1,Result2;
	Result1=Mat[0]+Mat[2];
	Result1.print();
	Result2=Mat[4].operator+(70);
	Result2.print();
	Mat[2].operator++();
	Mat[3]+=Mat[1];    				// OR .operator+=(Mat[1])
	Mat[3].print();



	return 0;

}
