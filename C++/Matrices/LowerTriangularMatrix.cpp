// LowerTriangularMatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
DOCUMENTATION: 

What is a Lower Triangular Matrix?
A lower triangular matrix is a type of matrix where the lower triangle of a matrix i = (n x n) will be filled with non 
zero elements.

A lower triangle matrix looks like:

1 0 0 0
1 2 0 0
1 2 3 0
1 2 3 4 

In the above matrix the positions occupied by 0's are in the upper half of the matrix.

For non zero elements in an upper triangular matrix the the value of index representing the rows say i will always
be greater than that of the say j that is representing the index of columns.

Mathematically:
M[i][j] = 0 for i < j
M[i][j] = nonZero for i >= j
(i represents the index of Rows and j represents the index of Columns)
*/


#include<iostream>
using namespace std;

class LowerTriangularMatrix {
private:
	int n;
	int* A;
public:
	LowerTriangularMatrix(int n);
	void SetRowMajor(int i, int j, int x);
	void SetColumnMajor(int i, int j, int x);
	int GetRowMajor(int i, int j);
	int GetColumnMajor(int i, int j);
	void display(bool row = true);
	int GetN();
};

LowerTriangularMatrix::LowerTriangularMatrix(int n) {
	this->n = n;
	A = new int[n * (n + 1) / 2];
}

void LowerTriangularMatrix::SetRowMajor(int i, int j, int x) {
	if (i >= j) {
		int index = ((i * (i - 1)) / 2) + j - 1;
		A[index] = x;
	}
}

void LowerTriangularMatrix::SetColumnMajor(int i, int j, int x) {
	if (i >= j) {
		int index = (n * (j - 1) - (((j - 2) * (j - 1)) / 2)) + (i - j);
		A[index] = x;
	}
}

int LowerTriangularMatrix::GetRowMajor(int i, int j) {
	if (i >= j) {
		int index = (((i * (i - 1)) / 2) + j - 1);
		return index;
	}
	else {
		return 0;
	}
}

int LowerTriangularMatrix::GetColumnMajor(int i, int j) {
	if (i >= j) {
		int index = (n * (j - 1) - (((j - 2) * (j - 1)) / 2)) + (i - j);
		return A[index];
	}
	else {
		return 0;
	}
}

void LowerTriangularMatrix::display(bool row) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (row) {
				cout << GetRowMajor(i, j) << " ";
			}
			else {
				cout << GetColumnMajor(i, j) << " ";
			}
		}
		cout << endl;
	}
}

int LowerTriangularMatrix::GetN() {
	return n;
}

int main() {
	LowerTriangularMatrix rm(4);
	rm.SetRowMajor(1, 1, 1);
	rm.SetRowMajor(2, 1, 2);
	rm.SetRowMajor(2, 2, 3);
	rm.SetRowMajor(3, 1, 4);
	rm.SetRowMajor(3, 2, 5);
	rm.SetRowMajor(3, 3, 6);
	rm.SetRowMajor(4, 1, 7);
	rm.SetRowMajor(4, 2, 8);
	rm.SetRowMajor(4, 3, 9);
	rm.SetRowMajor(4, 4, 10);

	rm.display();
	cout << endl;
	
	LowerTriangularMatrix cm(4);
	cm.SetColumnMajor(1, 1, 1);
	cm.SetColumnMajor(2, 1, 2);
	cm.SetColumnMajor(2, 2, 3);
	cm.SetColumnMajor(3, 1, 4);
	cm.SetColumnMajor(3, 2, 5);
	cm.SetColumnMajor(3, 3, 6);
	cm.SetColumnMajor(4, 1, 7);
	cm.SetColumnMajor(4, 2, 8);
	cm.SetColumnMajor(4, 3, 9);
	cm.SetColumnMajor(4, 4, 10);

	cm.display(false);
	
	return 0;
}
