#include <iostream>
#include <vector>
#include <algorithm>
#include "SquareMatrix.h"

template<typename T>
void print(std::vector<T> v) {
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    SquareMatrix a(1), b(2), c(3);

    std::cout << "Enter matrix a:\n";
    std::cin >> a;
    std::cout << "\n";
    std::cout << a;
    std::cout << "\n";

    std::cout << "Enter matrix b:\n";
    std::cin >> b;
    std::cout << "\n";
    std::cout << b;
    std::cout << "\n";

    std::cout << "Enter matrix c:\n";
    std::cin >> c;
    std::cout << "\n";
    std::cout << c;
    std::cout << "\n";

    std::vector<double> matrixVector = {a.determinant(), b.determinant(), c.determinant()};
    std::cout << "Before erase:\n";
    print(matrixVector);

    auto start = std::remove_if(
        matrixVector.begin(),
        matrixVector.end(),
        [](int element) {
            return element % 2 == 0;
        }
    );

    matrixVector.erase(start, matrixVector.end());
    std::cout << "\nAfter erase:\n";
    print(matrixVector);
}