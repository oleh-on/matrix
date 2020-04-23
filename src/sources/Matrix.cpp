//
// Created by olehon on 4/23/20.
//

#include "Matrix.h"

Matrix::Matrix() : matrix(new int*[SIZE]) {
    for (int i = 0; i < SIZE; ++i){
        matrix[i] = new int[SIZE];
    }
}

void Matrix::fill_matrix() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            matrix[i][j] = rand() % 10;
        }
    }
}

void Matrix::print_matrix() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

int **Matrix::getMatrix() {
    return matrix;
}

