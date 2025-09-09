#include <iostream>
#include <vector>
#include <cassert>
#include "Matrix.h"

using std::vector;
using std::cout;

Matrix::Matrix(int _row, int _col, float _gap): row(_row), col(_col), gap(_gap)
{
	m.resize(row);
	for (auto& _r : m) {
		_r.resize(col, 0);
	}

	// Hardcode Input
	float val = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			m[i][j] = val;
			val += gap;
		}
	}
}

Matrix::Matrix(vector<vector<float>> _m): m(_m), row(_m.size()), col(_m[0].size()) {}

Matrix::~Matrix() {}

Matrix Matrix::operator+(Matrix& _m1, Matrix& _m2)
{
	assert(_m1.row == _m2.row && _m1.col == _m2.col);
	vector<vector<float>> result(_m1.row, vector<float>(_m1.col, 0));
	for (int i = 0; i < _m1.row; i++) {
		for (int j = 0; j < _m1.col; j++) {
			result[i][j] = _m1.m[i][j] + _m2.m[i][j];
		}
	}

	return Matrix(result);
}
Matrix& Matrix::operator-=(Matrix& _matrix)
{
	assert(row == _matrix.row && col == _matrix.col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			m[i][j] -= _matrix.m[i][j];
		}
	}

	return *this;
}
Matrix Matrix::operator*(Matrix& _m)
{
	assert(col == _m.row);

	float new_value;
	vector<vector<float>> result(row, vector<float>(col, 0));
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < _m.col; j++) {
			new_value = 0;

			for (int k = 0; k < col; k++) {
				new_value += m[i][k] * _m.m[k][j];
			}

			result[i][j] = new_value;
		}
	}

	return Matrix(result);
}

void Matrix::print()
{
	cout << "[";
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << m[i][j];
			if (j != col - 1 || i != row - 1) {
				cout << ", ";
				if (j == col - 1) {
					cout << "\n";
				}
			}
		}
	}
	cout << "]\n";
}