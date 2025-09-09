#pragma once
#include <vector>

using namespace std;
class Matrix {
public:
	vector<vector<float>> m;
	int row, col;
	
	Matrix(float _gap, int _row, int _col);
	Matrix(vector<vector<float>> _m);
	~Matrix();

	Matrix operator+(Matrix& _m);
	Matrix operator-(Matrix& _m);
	Matrix operator*(Matrix& _m);

	void print();
};
