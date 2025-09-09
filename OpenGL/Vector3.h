#pragma once
#include <vector>

class Vector3 {
public:
	float x,y,z;

	Vector3(float _x, float _y, float _z);
	Vector3(std::vector<float> _v);
	~Vector3();

	Vector3 operator+(Vector3& _v);
	Vector3 operator-(Vector3& _v);
	Vector3 operator*(float scalar);
	Vector3 operator/(float scalar);

	float magnitude();
	float distance(Vector3& _v);
	float dot_product(Vector3& _v);
	Vector3 cross_product(Vector3& _v);
	Vector3 normalize();

	void print();
};
