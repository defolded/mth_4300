#pragma once

#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<double>> data;
    int rows, cols;

public:
    Matrix(int n, int m);
    Matrix(const std::vector<std::vector<double>>& values);

    Matrix operator+(const Matrix& other) const;
    Matrix operator*(double scalar) const;
    Matrix operator*(const Matrix& other) const;

    double determinant() const;
    double operator()(int row, int col) const;

    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
    friend std::istream& operator>>(std::istream& is, Matrix& m);
};
