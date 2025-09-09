#include <string>
#include <iostream>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/ext.hpp>
#include "Matrix.h"

using namespace std;
void to_string(glm::vec3 vtx) {
    cout << "{" << vtx.x << ", " << vtx.y << ", " << vtx.z << "}\n";
}

void task1() {
    glm::vec3 src, dst;
    float scalar;
    int steps;
    cout << "Enter source position: ";
    cin >> src.x >> src.y >> src.z;

    cout << "Enter destination position: ";
    cin >> dst.x >> dst.y >> dst.z;

    cout << "How fast you move: ";
    cin >> scalar;

    steps = ceil(glm::distance(src, dst) / scalar);
    cout << "You need to take " << steps << " steps.\n";
}

void task2() {
    glm::vec3 vtx1, vtx2, vtx3;
    float primeter, area, side1, side2, side3;
    cout << "Enter coordinate of the first vertex: ";
    cin >> vtx1.x >> vtx1.y >> vtx1.z;

    cout << "Enter coordinate of the second vertex: ";
    cin >> vtx2.x >> vtx2.y >> vtx2.z;

    cout << "Enter coordinate of the third vertex: ";
    cin >> vtx3.x >> vtx3.y >> vtx3.z;

    side1 = glm::distance(vtx1, vtx2);
    side2 = glm::distance(vtx2, vtx3);
    side3 = glm::distance(vtx3, vtx1);
    primeter = side1 + side2 + side3;
    area = sqrt(primeter / 2 * (primeter / 2 - side1) * (primeter / 2 - side2) * (primeter / 2 - side3));
    
    cout << "Primeter of the triangle is: " << primeter << ".\n";
    cout << "Area of the triangle is: " << area << ".\n";
}

void task3() {
    glm::vec3 vtx1, vtx2, vtx3, vtx4, vtx5, vtx6, vtx7, vtx8, side1, side2, side3, cross_prod;
    float depth;
    cout << "Enter coordinate of the first vertex: ";
    cin >> vtx1.x >> vtx1.y >> vtx1.z;

    cout << "Enter coordinate of the second vertex: ";
    cin >> vtx2.x >> vtx2.y >> vtx2.z;

    cout << "Enter coordinate of the third vertex: ";
    cin >> vtx3.x >> vtx3.y >> vtx3.z;

    cout << "Choose depth for the cube: ";
    cin >> depth;

    side1 = vtx2 - vtx1;
    side2 = vtx3 - vtx1;
    vtx4 = side1 + side2;
    //side3 = glm::distance(vtx3, vtx1);
    cross_prod = glm::normalize(glm::cross(side1, side2)) * depth;

    vtx5 = vtx1 + cross_prod;
    vtx6 = vtx2 + cross_prod;
    vtx7 = vtx3 + cross_prod;
    vtx8 = vtx4 + cross_prod;

    cout << "Eight coordinates of the cuboid are:\n";
    to_string(vtx1);
    to_string(vtx2);
    to_string(vtx3);
    to_string(vtx4);
    to_string(vtx5);
    to_string(vtx6);
    to_string(vtx7);
    to_string(vtx8);
}

void task4() {
    int row, col;
    cout << "Specify the dimension of a matrix (row, col):";
    cin >> row >> col;

    Matrix src_matrix(3, 3);
    Matrix tar_matrix(3, 3, 1);
    cout << "The initial matrix is: \n";
    src_matrix.print();

    cout << "The target matrix is: \n";
    tar_matrix.print();

    src_matrix += tar_matrix;
    src_matrix -= tar_matrix;
    src_matrix *
}

int main()
{
    //task1();
    //task2();
    //task3();
    task4();
    return 0;
}
