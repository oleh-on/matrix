//
// Created by olehon on 4/23/20.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <random>
#include <ctime>
#include <iostream>

const int SIZE = 1000;

class Matrix {
    int** matrix;
public:
    Matrix();
    ~Matrix() {delete[] matrix;};
    int** getMatrix();
    void fill_matrix();
    void print_matrix();
};


#endif //MATRIX_MATRIX_H
