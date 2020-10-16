// DataStructureMatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
using namespace std;
/*
Documentation on the class Diagonal Matrix:
	private members:
		int n -> This will have the size of the matrix
		int(pointer) a -> This will be used to create array dynamically
	public members:
		DigaonalMatrix(int n);
			This method is the constructor method and will create a new matrix whenever called of the passed size.
		void set(int i, int j,  int x);
			This method is taking i and j which are the coordinates row and column respectively, and int x is 
			storing the value of the element we need to store the element at [i][j].
		int get(int i, int j);
			This method will give us the value or element present in the coordinate [i][j]
		void display();
			This method will be called to display the diagonal matrix
		Last method is destructor which will be called to delete the array from the heap
*/



class DiagonalMatrix {
private:
	int n;
	int* a;
public:
	DiagonalMatrix(int n) {
		this->n = n;
		a = new int[n];
	}
	void set(int i, int j, int x);
	int get(int i, int j);
	void display();
	~DiagonalMatrix() {
		delete[]a;
	}
};

void DiagonalMatrix::set(int i, int j, int x) {
	if (i == j) {
		a[i - 1] = x;
	}
}

int DiagonalMatrix::get(int i, int j) {
	if (i == j) {
		return a[i - 1];
	}
	else {
		return 0;
	}
}

void DiagonalMatrix::display() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) {
				cout << a[i - 1] << " ";
			}
			else {
				cout << "0" << " ";
			}
		}
		cout << endl;
	}
}

int main() {
	DiagonalMatrix matrix(3);

	matrix.set(1, 1, 1);
	matrix.set(2, 2, 2);
	matrix.set(3, 3, 3);

	matrix.display();
	return 0;
}

