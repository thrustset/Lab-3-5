#include <iostream>
#include "matrix.h"

Matrix::Matrix() {
    value = nullptr;
}

Matrix::Matrix(char newName, int newNOR, int newNOC) {
    name = newName;
    numOfRows = newNOR;
    numOfColumns = newNOC;

    value = new double*[numOfRows];
    for(int i = 0; i < numOfRows; i++)
        value[i] = new double[numOfColumns];
}

Matrix::Matrix(char newName, Matrix &source) {
    name = newName;
    numOfRows = source.getNOR();
    numOfColumns = source.getNOC();

    value = new double*[numOfRows];
    for(int i = 0; i < numOfRows; i++) {
        value[i] = new double[numOfColumns];
        for(int j = 0; j < numOfColumns; j++)
            value[i][j] = source.getValue(i, j);
    }
}

Matrix::~Matrix() {
    for(int i = 0; i < numOfRows; i++)
        delete [] value[i];
    delete [] value;
}

char Matrix::getName() const {
    return name;
}

int Matrix::getNOR() const {
    return numOfRows;
}

int Matrix::getNOC() const {
    return numOfColumns;
}

double Matrix::getValue(int i, int j) const {
    return value[i][j];
}

void Matrix::setValue(int i, int j, double newValue) {
    if(i < numOfRows && j < numOfColumns)
        value[i][j] = newValue;
    else
        std::cout << "Error in setValue()! Matrix: " << name << "\n";
}

void Matrix::expand(Matrix &addition) {
    if(numOfRows != addition.getNOR()) {
        std::cout << "Can not join matrix " << addition.getName() << " to " << name << "!\n";
    } else {
        auto **tmpValue = new double*[numOfRows];

        for(int i = 0; i < numOfRows; i++) {
            tmpValue[i] = new double[numOfColumns + addition.getNOC()];
            for(int j = 0; j < numOfColumns; j++)
                tmpValue[i][j] = value[i][j];
            for(int j = numOfColumns; j < numOfColumns + addition.getNOC(); j++)
                tmpValue[i][j] = addition.getValue(i, j - numOfColumns);
        }

        numOfColumns += addition.getNOC();

        for(int i = 0; i < numOfRows; i++) {
            delete[] value[i];
            value[i] = new double[numOfColumns];
            for(int j = 0; j < numOfColumns; j++)
                value[i][j] = tmpValue[i][j];
            delete [] tmpValue[i];
        }
        delete [] tmpValue;
    }
}

void Matrix::modify(double (*func)(double)) {
    if(func) {
        for(int i = 0; i < numOfRows; i++) {
            for(int j = 0; j < numOfColumns; j++)
                value[i][j] = func(value[i][j]);
        }
    }
}

void Matrix::print() const {
    std::cout << "Matrix " << name << ":\n";
    for(int i = 0; i < numOfRows; i++) {
        for(int j = 0; j < numOfColumns; j++)
            printf("%.2f\t", value[i][j]);
        std::cout << "\n";
    }
    std::cout << "\n";
}
