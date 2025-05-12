#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include "SquareMatrix.h"

template<typename T>
void printVector(std::vector<T> vector) {
    for (int i = 0; i < vector.size(); ++i) {
        std::cout << vector[i] << " ";
    }
    std::cout << "\n";
}


void printMenu() {
    std::cout << "\n\n---MENU---\n\n";
    std::cout << "1. Sort vector\n";
    std::cout << "2. Remove elements\n";
    std::cout << "3. Exit\n";
}


int main() {
    srand(time(0));
    SquareMatrix a(1), b(2), c(3), d(4), e(5);
    std::vector<int> determinantVector;
    int choice;

    
    while (true) {
        a.fillMatrix();
        b.fillMatrix();
        c.fillMatrix();
        d.fillMatrix();
        e.fillMatrix();

        printMenu();
        std::cout << "\nChoice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                determinantVector = {a.determinant(), b.determinant(), c.determinant(), d.determinant(), e.determinant()};

                std::cout << "Vector defore sort:\n";
                printVector(determinantVector);

                std::sort(
                    determinantVector.begin(),
                    determinantVector.end(),
                    [](const int& element1, const int& element2) {
                        return element1 < element2;
                    }
                );

                std::cout << "Vector after sort:\n";
                printVector(determinantVector);

                system("pause");
                system("cls");
                break;
            }

            case 2: {
                determinantVector = {a.determinant(), b.determinant(), c.determinant(), d.determinant(), e.determinant()};

                std::cout << "Vector defore remove:\n";
                printVector(determinantVector);

                determinantVector.erase (
                    std::remove_if(
                        determinantVector.begin(),
                        determinantVector.end(),
                        [](const int& element) {
                            return element % 2 == 0;
                        }
                    ),
                    determinantVector.end()
                );

                std::cout << "Vector after remove:\n";
                printVector(determinantVector);

                system("pause");
                system("cls");
                break;
            }

            case 3:
                exit(0);
                break;

            default:
                system("cls");
                continue;
        }
    }
}