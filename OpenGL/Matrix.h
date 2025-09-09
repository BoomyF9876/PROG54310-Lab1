#pragma once
#include <iostream>
#include <vector>

using namespace std;
class Matrix {
	public:
		vector<vector<float>> m;
		int row, col;
		float gap;
	
		Matrix(int _row, int _col, float _gap = 0.5f);
		Matrix(vector<vector<float>> _m);
		~Matrix();

		Matrix operator+(Matrix& _m1, Matrix& _m2);
		Matrix operator-(Matrix& _m1, Matrix& _m2);
		Matrix operator*(Matrix& _m1, Matrix& _m2);

		void print();
};
