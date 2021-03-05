#include <iostream>
#include <cmath>
#include "matrix.h"

int main() {
    unsigned int A_NOR = 3, A_NOC = 3;
    unsigned int B_NOR = 3, B_NOC = 2;

    auto *A = new Matrix('A', A_NOR, A_NOC);
    for(unsigned int i = 0; i < A_NOR; i++) {
        for(unsigned int j = 0; j < A_NOC; j++)
            A->setValue(i, j, 3 * i + j + 1);
    }

    auto *B = new Matrix('B', B_NOR, B_NOC);
    for(unsigned int i = 0; i < B_NOR; i++) {
        for(unsigned int j = 0; j < B_NOC; j++)
            B->setValue(i, j, 2 * i + j + 11);
    }

    A->print();
    B->print();

    auto *C = new Matrix('C', *A);
    C->print();

    std::cout << "Expand ";
    C->expand(*B);
    C->print();

    std::cout << "Modify ";
    C->modify(sqrt);
    C->print();

    delete A;
    delete B;
    delete C;

    return 0;
}
