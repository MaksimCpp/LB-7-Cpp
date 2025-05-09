#include "SquareMatrix.h"
#include <iostream>
#include <stdexcept>
#include "math.h"

SquareMatrix::SquareMatrix() {}

SquareMatrix::~SquareMatrix() {
    for (int i = 0; i < length; ++i) {
        delete[] this->matrix[i];
    }
    delete[] this->matrix;
}

SquareMatrix::SquareMatrix(const SquareMatrix& matr) {
    this->matrix = new double*[length];
    for (int i = 0; i < length; ++i) {
        this->matrix[i] = new double[length];
    }

    this->length = matr.length;
    this->matrix = matr.matrix;
}

SquareMatrix::SquareMatrix(int length):
            length(length)  
            {
                this->matrix = new double*[length];
                for (int i = 0; i < length; ++i) {
                    this->matrix[i] = new double[length];
                }
            }

SquareMatrix operator*(const SquareMatrix& matr, double num) {
    SquareMatrix mt(matr.length);

    for (int i = 0; i < matr.length; ++i) {
        for (int j = 0; j < matr.length; ++j) {
            mt.matrix[i][j] = matr.matrix[i][j] * num;
        }
    }

    return mt;
}

double SquareMatrix::determinant() {
    if (length == 0) return 0;

    // Создаем копию матрицы, чтобы не изменять оригинальную
    double** tempMat = new double*[length];
    for (int i = 0; i < length; i++) {
        tempMat[i] = new double[length];
        for (int j = 0; j < length; j++) {
            tempMat[i][j] = matrix[i][j];
        }
    }

    double det = 1.0; // Изначальное значение определителя

    // Приводим матрицу к верхнетреугольному виду методом Гаусса
    for (int col = 0; col < length; col++) {
        // Ищем строку с максимальным элементом в текущем столбце
        int maxRow = col;
        for (int row = col + 1; row < length; row++) {
            if (std::abs(tempMat[row][col]) > std::abs(tempMat[maxRow][col])) {
                maxRow = row;
            }
        }

        // Если максимальный элемент равен 0 (с точностью до погрешности), 
        // то определитель 0
        if (std::abs(tempMat[maxRow][col]) < 1e-10) {
            // Освобождаем память перед выходом
            for (int i = 0; i < length; i++) {
                delete[] tempMat[i];
            }
            delete[] tempMat;
            return 0.0;
        }

        // Меняем местами текущую строку и строку с максимальным элементом
        if (maxRow != col) {
            std::swap(tempMat[col], tempMat[maxRow]);
            det *= -1; // При перестановке строк знак определителя меняется
        }

        // Зануляем элементы ниже текущего диагонального элемента
        for (int row = col + 1; row < length; row++) {
            double factor = tempMat[row][col] / tempMat[col][col];
            for (int k = col; k < length; k++) {
                tempMat[row][k] -= factor * tempMat[col][k];
            }
        }
    }

    // Вычисляем определитель как произведение диагональных элементов
    for (int i = 0; i < length; i++) {
        det *= tempMat[i][i];
    }

    // Освобождаем память временной матрицы
    for (int i = 0; i < length; i++) {
        delete[] tempMat[i];
    }
    delete[] tempMat;

    return det;
}

SquareMatrix operator*(double num, const SquareMatrix& matr) {
    SquareMatrix mt(matr.length);

    for (int i = 0; i < matr.length; ++i) {
        for (int j = 0; j < matr.length; ++j) {
            mt.matrix[i][j] = matr.matrix[i][j] * num;
        }
    }

    return mt;
}

void SquareMatrix::setLength(int length) {
    this->length = length;
}

SquareMatrix SquareMatrix::operator*(const SquareMatrix& matr) {
    if (this->length != matr.length) {
        throw std::invalid_argument("Size error");
    }

    SquareMatrix mtr(length);
    for (int i = 0; i < this->length; ++i) {
        for (int j = 0; j < this->length; ++j) {
            mtr.matrix[i][j] = 0;

            for (int k = 0; k < this->length; ++k) {
                mtr.matrix[i][j] += this->matrix[i][k] * matr.matrix[k][j];
            }
        }
    }

    return mtr;
}

SquareMatrix operator+(const SquareMatrix& matr, double num) {
    SquareMatrix mt(matr.length);

    for (int i = 0; i < matr.length; ++i) {
        for (int j = 0; j < matr.length; ++j) {
            mt.matrix[i][j] = matr.matrix[i][j] + num;
        }
    }

    return mt;
}

SquareMatrix operator+(double num, const SquareMatrix& matr) {
    SquareMatrix mt(matr.length);

    for (int i = 0; i < matr.length; ++i) {
        for (int j = 0; j < matr.length; ++j) {
            mt.matrix[i][j] = matr.matrix[i][j] + num;
        }
    }

    return mt;
}

SquareMatrix SquareMatrix::operator+(const SquareMatrix& matr) {
    if (this->length != matr.length) {
        throw std::invalid_argument("Size error");
    }

    SquareMatrix mtr(this->length);
    for (int i = 0; i < this->length; ++i) {
        for (int j = 0; j < this->length; ++j) {
            mtr.matrix[i][j] = this->matrix[i][j] + matr.matrix[i][j];
        }
    }

    return mtr;
}

void SquareMatrix::printMatrix() const {
    for (int i = 0; i < this->length; ++i) {
        for (int j = 0; j < this->length; ++j) {
            std::cout << this->matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

void SquareMatrix::fillMatrix() const {
    for (int i = 0; i < this->length; ++i) {
        for (int j = 0; j < this->length; ++j) {
            this->matrix[i][j] = rand() % 10;
        }
    }
}

double* SquareMatrix::operator[](unsigned int index) {
    return this->matrix[index];
}

std::ostream& operator<<(std::ostream& stream, const SquareMatrix& matr) {
    for (int i = 0; i < matr.length; ++i) {
        for (int j = 0; j < matr.length; ++j) {
            stream << matr.matrix[i][j] << ' ';
        }
        stream << '\n';
    }
    return stream;
}

int SquareMatrix::getLength() const {
    return this->length;
}

SquareMatrix SquareMatrix::operator=(const SquareMatrix& matr) {
    if (this->length == matr.length) {
        return *this;
    }

    for (int i = 0; i < this->length; ++i) {
        delete[] this->matrix[i];
    }

    delete[] this->matrix;
    this->length = matr.length;
    this->matrix = new double*[this->length];

    for (int i = 0; i < this->length; ++i) {
        this->matrix[i] = new double[this->length];
    }

    for (int i = 0; i < this->length; ++i) {
        for (int j = 0; j < this->length; ++j) {
            this->matrix[i][j] = matr.matrix[i][j];
        }
    }

    return *this;
}

std::istream& operator>>(std::istream& stream, const SquareMatrix& matr) {
    for (int i = 0; i < matr.length; ++i) {
        for (int j = 0; j < matr.length; ++j) {
            std::cout << "Element number " << i << " " << j << ": ";
            stream >> matr.matrix[i][j];
        }
    }
    
    return stream;
}

void SquareMatrix::transposition() {
    for (int i = 0; i < this->length; ++i) {
        for (int j = i + 1; j < this->length; ++j) {
            std::swap(this->matrix[i][j], this->matrix[j][i]);
        }
    }
}