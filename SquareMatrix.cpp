#include "SquareMatrix.h"
#include <iostream>
#include <random>

SquareMatrix::SquareMatrix() : size(0), matrix(nullptr) {}


SquareMatrix::SquareMatrix(int size) : size(size), matrix(nullptr) {
    allocateMemory();
}
    

SquareMatrix::SquareMatrix(const SquareMatrix& other) : size(0), matrix(nullptr) {
    copyFrom(other);
}
    

SquareMatrix& SquareMatrix::operator=(const SquareMatrix& other) {
    if (this != &other) {
        deallocateMemory();
        copyFrom(other);
    }
    return *this;
}
    

SquareMatrix::~SquareMatrix() {
    deallocateMemory();
}
    

int SquareMatrix::determinant() const {
    if (size == 0) return 0;

    SquareMatrix temp(*this);
    int det = 1;
        
    for (int i = 0; i < size; ++i) {
        int pivot = i;
        for (int j = i + 1; j < size; ++j) {
            if (abs(temp.matrix[j][i]) > abs(temp.matrix[pivot][i])) {
                pivot = j;
            }
        }
            
        if (pivot != i) {
            std::swap(temp.matrix[i], temp.matrix[pivot]);
            det = -det;
        }
            
        if (temp.matrix[i][i] == 0) {
            return 0; 
        }
            
        for (int j = i + 1; j < size; ++j) {
            double factor = static_cast<double>(temp.matrix[j][i]) / temp.matrix[i][i];
            for (int k = i; k < size; ++k) {
                temp.matrix[j][k] -= static_cast<int>(factor * temp.matrix[i][k]);
            }
        }
            
        det *= temp.matrix[i][i];
    }
        
    return det;
}
    
void SquareMatrix::printMatrix() const {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}
    
void SquareMatrix::fillMatrix() {
    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            this->matrix[i][j] = rand() % 50;
        }
    }
}
    
int SquareMatrix::getSize() const { return size; }
