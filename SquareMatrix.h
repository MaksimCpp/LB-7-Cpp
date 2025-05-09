#pragma once
#include <iostream>

class SquareMatrix {
private:
    int length;
    double** matrix;

public:
    SquareMatrix();
    ~SquareMatrix();
    SquareMatrix(int length);   
    SquareMatrix(const SquareMatrix& matr);
    SquareMatrix operator*(const SquareMatrix& matr);
    SquareMatrix operator+(const SquareMatrix& matr);
    SquareMatrix operator=(const SquareMatrix& matr);
    double* operator[](unsigned int index);
    void transposition();
    double determinant();
    void printMatrix() const;
    void fillMatrix() const;
    int getLength() const;
    void setLength(int length);
    friend SquareMatrix operator*(const SquareMatrix& matr, double num);
    friend SquareMatrix operator*(double num, const SquareMatrix& matr);
    friend SquareMatrix operator+(const SquareMatrix& matr, double num);
    friend SquareMatrix operator+(double num, const SquareMatrix& matr);
    friend std::ostream& operator<<(std::ostream& stream, const SquareMatrix& matr);
    friend std::istream& operator>>(std::istream& stream, const SquareMatrix& matr);
};
