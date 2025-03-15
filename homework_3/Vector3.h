#pragma once

#include <iostream>
#include <cmath>

class Vector3 {
private:
    double vec[3];

public:
    Vector3(double x = 0, double y = 0, double z = 0);

    Vector3 operator+(const Vector3& other) const;
    Vector3 operator-(const Vector3& other) const;
    Vector3 operator*(double scalar) const;
    Vector3 operator/(double scalar) const;
    bool operator==(const Vector3& other) const;

    double magnitude() const;

    double operator()(int index) const;  // Access operator

    friend std::ostream& operator<<(std::ostream& out, const Vector3& v);
    friend std::istream& operator>>(std::istream& in, Vector3& v);
};