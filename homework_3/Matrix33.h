#pragma once

#include <iostream>
#include "Vector3.h"

class Matrix33 {
private:
    double matrix[3][3];

public:
    Matrix33();
    Matrix33(const double arr[3][3]);

    Matrix33 operator*(const Matrix33& m) const;
    Matrix33 operator*(int c) const;
    Matrix33 operator+(const Matrix33& m) const;

    double determinant() const;
    double operator()(int row, int col) const;

    friend std::ostream& operator<<(std::ostream& os, const Matrix33& m);
    friend std::istream& operator>>(std::istream& is, Matrix33& m);
};