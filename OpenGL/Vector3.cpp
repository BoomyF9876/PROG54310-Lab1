#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "Vector3.h"
using std::cout;

Vector3::Vector3(float _x, float _y, float _z): x(_x), y(_y), z(_z) {}
Vector3::Vector3(std::vector<float> _v): x(_v[0]), y(_v[1]), z(_v[2]) {}
Vector3::~Vector3() {}

Vector3 Vector3::operator+(Vector3& _v)
{
	return Vector3(x + _v.x, y + _v.y, z + _v.z);
}
Vector3 Vector3::operator-(Vector3& _v)
{
	return Vector3(x - _v.x, y - _v.y, z - _v.z);
}
Vector3 Vector3::operator*(float scalar)
{
	return Vector3(x * scalar, y * scalar, z * scalar);
}
Vector3 Vector3::operator/(float scalar)
{
	return Vector3(x / scalar, y / scalar, z / scalar);
}

float Vector3::magnitude()
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}
float Vector3::distance(Vector3& _v)
{
	return sqrt(pow(x - _v.x, 2) + pow(y - _v.y, 2) + pow(z - _v.z, 2));
}
float Vector3::dot_product(Vector3& _v)
{
	return x * _v.x + y * _v.y + z * _v.z;
}
Vector3 Vector3::cross_product(Vector3& _v)
{
	return Vector3(y * _v.z - z * _v.y, z * _v.x - x * _v.z, x * _v.y - y * _v.x);
}
Vector3 Vector3::normalize()
{
	float mag = magnitude();
	return Vector3(x / mag, y / mag, z / mag);
}

void Vector3::print()
{
	cout << "{" << x << ", " << y << ", " << z << "}\n";
}
