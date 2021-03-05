#pragma once

class Matrix {
private:
    unsigned char name;
    unsigned int numOfRows;
    unsigned int numOfColumns;
    double **value;

public:
    Matrix();
    Matrix(unsigned char newName, unsigned int newNOR, unsigned int newNOC);
    Matrix(unsigned char newName, Matrix &source);
    ~Matrix();

    unsigned char getName() const;
    unsigned int getNOR() const;
    unsigned int getNOC() const;

    double getValue(unsigned int i, unsigned int j) const;
    void setValue(unsigned int i, unsigned int j, double newValue);

    void expand(Matrix &addition);
    void modify(double (*func)(double) = nullptr);
    void print() const;
};