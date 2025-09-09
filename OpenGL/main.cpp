#include <string>
#include <iostream>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/ext.hpp>
#include "Matrix.h"
#include "Vector3.h"

using std::cout;
using std::cin;
using std::endl;

void task1() {
    glm::vec3 src(0, 0, 0), dst(0, 3, 4);
    float scalar = 0.4f;
    int steps;

    cout << "--------------------Task 1--------------------\n";
    cout << "Source position: " << glm::to_string(src) << endl;
    cout << "Destination position: " << glm::to_string(dst) << endl;
    cout << "How fast you move: " << scalar <<endl;

    steps = ceil(glm::distance(src, dst) / scalar);
    cout << "\nYou need to take " << steps << " steps.\n";
}

void task2() {
    glm::vec3 vtx1(0, 0, 0), vtx2(1, 2, 3), vtx3(3, 3, 3);
    float primeter, area, side1, side2, side3;

    cout << "\n--------------------Task 2--------------------\n";
    cout << "Coordinate of the first vertex: " << glm::to_string(vtx1) << endl;
    cout << "Coordinate of the second vertex: " << glm::to_string(vtx2) << endl;
    cout << "Coordinate of the third vertex: " << glm::to_string(vtx3) << endl;

    side1 = glm::distance(vtx1, vtx2);
    side2 = glm::distance(vtx2, vtx3);
    side3 = glm::distance(vtx3, vtx1);
    primeter = side1 + side2 + side3;
    area = sqrt(primeter / 2 * (primeter / 2 - side1) * (primeter / 2 - side2) * (primeter / 2 - side3));
    
    cout << "\nPrimeter of the triangle is: " << primeter << endl;
    cout << "Area of the triangle is: " << area << endl;
}

void task3() {
    glm::vec3 vtx1(0, 0, 0), vtx2(1, 2, 3), vtx3(4, 4, 4), vtx4, vtx5, vtx6, vtx7, vtx8, side1, side2, side3, cross_prod;
    float depth = 3.5f;

    cout << "\n--------------------Task 3--------------------\n";
    cout << "Coordinate of the first vertex: " << glm::to_string(vtx1) << endl;
    cout << "Coordinate of the second vertex: " << glm::to_string(vtx2) << endl;
    cout << "Coordinate of the third vertex: " << glm::to_string(vtx3) << endl;
    cout << "Depth for the cube: " << depth << endl;

    side1 = vtx2 - vtx1;
    side2 = vtx3 - vtx1;
    vtx4 = side1 + side2;
    //side3 = glm::distance(vtx3, vtx1);
    cross_prod = glm::normalize(glm::cross(side1, side2)) * depth;

    vtx5 = vtx1 + cross_prod;
    vtx6 = vtx2 + cross_prod;
    vtx7 = vtx3 + cross_prod;
    vtx8 = vtx4 + cross_prod;

    cout << "\nEight coordinates of the cuboid are:\n";
    cout << glm::to_string(vtx1) << endl;
    cout << glm::to_string(vtx2) << endl;
    cout << glm::to_string(vtx3) << endl;
    cout << glm::to_string(vtx4) << endl;
    cout << glm::to_string(vtx5) << endl;
    cout << glm::to_string(vtx6) << endl;
    cout << glm::to_string(vtx7) << endl;
    cout << glm::to_string(vtx8) << endl;
}

void task4() {
    Matrix src_matrix(2, 3, 3);
    Matrix tar_matrix(1, 3, 3);

    Matrix result1 = src_matrix + tar_matrix;
    Matrix result2 = src_matrix - tar_matrix;
    Matrix result3 = src_matrix * tar_matrix;

    // Compare result with glm output
    glm::mat3 glm_src = {
        {0, 2, 4},
        {6, 8, 10},
        {12, 14, 16}
    };
    glm::mat3 glm_tar = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8}
    };

    cout << "\n-----------Task 4 (Verify matrix functions)-----------\n";
    cout << "Input matrix 1:\n";
    src_matrix.print();

    cout << "Input matrix 2:\n";
    tar_matrix.print();

    cout << "\nMatrix addition result:\n";
    result1.print();
    cout << "glm addtion output:\n" << glm::to_string(glm_src + glm_tar)<<endl;

    cout << "\nMatrix subtraction result:\n";
    result2.print();
    cout << "glm subtraction output:\n" << glm::to_string(glm_src - glm_tar) << endl;

    cout << "\nMatrix multiplication result:\n";
    result3.print();
    cout << "glm multiplication output:\n" << glm::to_string(glm_src * glm_tar) << endl;
}

void verify_vector() {
    Vector3 src_vec(1, 2, 3);
    Vector3 tar_vec(4, 5, 6);
    float scalar = 2.0f;
    
    glm::vec3 glm_src = { 1, 2, 3 };
    glm::vec3 glm_tar = { 4, 5, 6 };

    Vector3 result1 = src_vec + tar_vec;
    Vector3 result2 = src_vec - tar_vec;
    Vector3 result3 = src_vec * scalar;
    Vector3 result4 = src_vec / scalar;
    float result5 = src_vec.magnitude();
    Vector3 result6 = src_vec.normalize();
    float result7 = src_vec.distance(tar_vec);
    float result8 = src_vec.dot_product(tar_vec);
    Vector3 result9 = src_vec.cross_product(tar_vec);

    cout << "\n---------------Verify vector functions---------------\n";
    cout << "Input vector1: ";
    src_vec.print();
    cout << "Input vector2: ";
    tar_vec.print();

    cout << "\nVector addition result: ";
    result1.print();
    cout << "glm addtion output: " << glm::to_string(glm_src + glm_tar) << endl;

    cout << "\nVector subtraction result: ";
    result2.print();
    cout << "glm subtraction output: " << glm::to_string(glm_src - glm_tar) << endl;

    cout << "\nVector scalar result: ";
    result3.print();
    cout << "glm scalar output: " << glm::to_string(glm_src * scalar) << endl;

    cout << "\nVector division result: ";
    result4.print();
    cout << "glm division output: " << glm::to_string(glm_src / scalar) << endl;

    cout << "\nVector magnitude result: " << result5 << endl;
    cout << "glm magnitude output: " << glm::length(glm_src) << endl;

    cout << "\nVector normalize result: ";
    result6.print();
    cout << "glm normalize output: " << glm::to_string(glm::normalize(glm_src)) << endl;

    cout << "\nVector distance result: " << result7 << endl;
    cout << "glm distance output: " << glm::distance(glm_src, glm_tar) << endl;

    cout << "\nVector dot product result: " << result8 << endl;
    cout << "glm dot product output: " << glm::dot(glm_src, glm_tar) << endl;

    cout << "\nVector cross product result: ";
    result9.print();
    cout << "glm cross product output: " << glm::to_string(glm::cross(glm_src, glm_tar)) << endl;
}

int main()
{
    task1();
    task2();
    task3();
    task4();
    verify_vector();
    return 0;
}
