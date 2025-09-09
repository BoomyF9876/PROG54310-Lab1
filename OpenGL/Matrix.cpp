#include <iostream>
#include <vector>
#include <cassert>
#include "Matrix.h"

using std::vector;
using std::cout;

Matrix::Matrix(float _gap, int _row, int _col): row(_row), col(_col)
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
			val += _gap;
		}
	}
}

Matrix::Matrix(vector<vector<float>> _m): m(_m), row(_m.size()), col(_m[0].size()) {}

Matrix::~Matrix() {}

Matrix Matrix::operator+(Matrix& _m)
{
	assert(row == _m.row && col == _m.col);
	vector<vector<float>> result(row, vector<float>(col, 0));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			result[i][j] = m[i][j] + _m.m[i][j];
		}
	}

	return Matrix(result);
}
Matrix Matrix::operator-(Matrix& _m)
{
	assert(row == _m.row && col == _m.col);
	vector<vector<float>> result(row, vector<float>(col, 0));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			result[i][j] = m[i][j] - _m.m[i][j];
		}
	}

	return Matrix(result);
}
Matrix Matrix::operator*(Matrix& _m)
{
	assert(col == _m.row);

	float new_value;
	vector<vector<float>> result(row, vector<float>(_m.col, 0));
	
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