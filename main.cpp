#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include "SquareMatrix.h"

void printMenu() {
    std::cout << "\n\n---MENU---\n\n";
    std::cout << "1. Sort\n";
    std::cout << "2. Remove elemets\n";
    std::cout << "3. Exit\n";
}

int main() {
    srand(time(0));
    int choice;
    std::vector<SquareMatrix> matrices;

    while (true) {
        printMenu();
        std::cout << "\nChoice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                for (int i = 0; i < 5; ++i) {
                    SquareMatrix m(2);
                    m.fillMatrix();
                    matrices.push_back(m);
                }

                std::cout << "\nBefore sorting by determinant:\n";
                for (size_t i = 0; i < matrices.size(); ++i) {
                    std::cout << matrices[i].determinant() << " ";
                }
                std::cout << std::endl;

                std::sort(
                    matrices.begin(), 
                    matrices.end(),
                    [](const SquareMatrix& a, const SquareMatrix& b) {
                        return a.determinant() < b.determinant();
                    }
                );
                
                std::cout << "\nAfter sorting by determinant:\n";
                for (size_t i = 0; i < matrices.size(); ++i) {
                    std::cout << matrices[i].determinant() << " ";
                }
                std::cout << std::endl;

                system("pause");
                system("cls");
                break;
            }

            case 2: {
                for (int i = 0; i < 5; ++i) {
                    SquareMatrix m(2);
                    m.fillMatrix();
                    matrices.push_back(m);
                }

                std::cout << "\nBefore remove:\n";
                for (size_t i = 0; i < matrices.size(); ++i) {
                    std::cout << matrices[i].determinant() << " ";
                }
                std::cout << std::endl;

                matrices.erase(
                    std::remove_if(
                        matrices.begin(), 
                        matrices.end(),
                        [](const SquareMatrix& m) { 
                            return m.determinant() % 2 == 0; 
                        }
                    ),
                    matrices.end()
                );
                
                std::cout << "\nAfter sorting by determinant:\n";
                for (size_t i = 0; i < matrices.size(); ++i) {
                    std::cout << matrices[i].determinant() << " ";
                }
                std::cout << std::endl;

                system("pause");
                system("cls");
                break;
            }

            case 3:
                exit(1);
                break;

            default:
                system("cls");
                continue;
        }
    }   
    
    return 0;
}