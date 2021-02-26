#pragma once

class Matrix {
private:
    char name{};
    int numOfRows{};
    int numOfColumns{};
    double **value;

public:
    Matrix();
    Matrix(char newName, int newNOR, int newNOC);
    Matrix(char newName, Matrix &source);
    ~Matrix();

    char getName() const;
    int getNOR() const;
    int getNOC() const;

    double getValue(int i, int j) const;
    void setValue(int i, int j, double newValue);

    void expand(Matrix &addition);
    void modify(double (*func)(double) = nullptr);
    void print() const;
};