#include <iostream>


/*
 * Problem 1: Book class
*/

class Book {
private:
    std::string title;
    std::string author;
    int yearPublished;
    double price;

public:
    Book(std::string &bookTitle, std::string &bookAuthor, int publishedYear = 1900, double bookPrice = 0.0) : title(
            bookTitle), author(bookAuthor), yearPublished(publishedYear), price(bookPrice) {}

    void applyDiscount(double &discount) {
        if (discount < 100) {
            price *= (1 - discount / 100);
        } else {
            price = 0;
        }
    }

    std::string getBookInfo() const {
        return "Title: " + title + ", Author: " + author +
               ", Year: " + std::to_string(yearPublished) +
               ", Price: $" + std::to_string(price);
    }

};

/*
 * Problem 2: Matrix class
*/

#include "Matrix33.h"

Matrix33::Matrix33() {}

Matrix33::Matrix33(const double arr[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrix[i][j] = arr[i][j];
        }
    }
}

Matrix33 Matrix33::operator*(const Matrix33& m) const {
    Matrix33 res;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            res.matrix[i][j] = 0;
            for (int k = 0; k < 3; ++k) {
                res.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
            }
        }
    }
    return res;
}

Matrix33 Matrix33::operator*(int c) const {
    Matrix33 res;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            res.matrix[i][j] = matrix[i][j] * c;
        }
    }
    return res;
}

Matrix33 Matrix33::operator+(const Matrix33& m) const {
    Matrix33 res;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            res.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
        }
    }
    return res;
}

std::ostream& operator<<(std::ostream& os, const Matrix33& m) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            os << m.matrix[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Matrix33& m) {
    std::cout << "Enter 9 values: " << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            is >> m.matrix[i][j];
        }
    }
    return is;
}

double Matrix33::operator()(int row, int col) const {
    return matrix[row][col];
}

double Matrix33::determinant() const {
    return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
           - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
           + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
}

/*
 * Problem 3: Vector3 class
*/

#include "Vector3.h"

Vector3::Vector3(double x, double y, double z) {
    vec[0] = x;
    vec[1] = y;
    vec[2] = z;
}

Vector3 Vector3::operator+(const Vector3& other) const {
    return Vector3(vec[0] + other.vec[0], vec[1] + other.vec[1], vec[2] + other.vec[2]);
}

Vector3 Vector3::operator-(const Vector3& other) const {
    return Vector3(vec[0] - other.vec[0], vec[1] - other.vec[1], vec[2] - other.vec[2]);
}

Vector3 Vector3::operator*(double scalar) const {
    return Vector3(vec[0] * scalar, vec[1] * scalar, vec[2] * scalar);
}

Vector3 Vector3::operator/(double scalar) const {
    return Vector3(vec[0] / scalar, vec[1] / scalar, vec[2] / scalar);
}

bool Vector3::operator==(const Vector3& other) const {
    return vec[0] == other.vec[0] && vec[1] == other.vec[1] && vec[2] == other.vec[2];
}

double Vector3::magnitude() const {
    return sqrt(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]);
}

double Vector3::operator()(int index) const {
    if (index >= 0 && index < 3) {
        return vec[index];
    }
    return 0;
}

std::ostream& operator<<(std::ostream& out, const Vector3& v) {
    out << "(" << v.vec[0] << ", " << v.vec[1] << ", " << v.vec[2] << ")";
    return out;
}

std::istream& operator>>(std::istream& in, Vector3& v) {
    std::cout << "Enter three values for the vector: ";
    in >> v.vec[0] >> v.vec[1] >> v.vec[2];
    return in;
}

Vector3 computeAx(const Matrix33& A, const Vector3& x) {
    return Vector3(
            A(0, 0) * x(0) + A(0, 1) * x(1) + A(0, 2) * x(2),
            A(1, 0) * x(0) + A(1, 1) * x(1) + A(1, 2) * x(2),
            A(2, 0) * x(0) + A(2, 1) * x(1) + A(2, 2) * x(2)
    );
}


/*
 * Problem 4: Matrix class
*/

#include "MatrixNxN.h"

Matrix::Matrix(int n, int m) : rows(n), cols(m), data(n, std::vector<double>(m, 0)) {}

Matrix::Matrix(const std::vector<std::vector<double>>& v)
        : rows(v.size()), cols(v[0].size()), data(v) {}

Matrix Matrix::operator+(const Matrix& m) const {
    if (rows != m.rows || cols != m.cols) {
        std::cout << "Dimension differs\n";
        return Matrix(rows, cols);
    }
    Matrix res(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            res.data[i][j] = data[i][j] + m.data[i][j];
        }
    }
    return res;
}

Matrix Matrix::operator*(double s) const {
    Matrix res(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            res.data[i][j] = data[i][j] * s;
        }
    }
    return res;
}

Matrix Matrix::operator*(const Matrix& m) const {
    if (cols != m.rows) {
        std::cout << "Error: Matrices cannot be multiplied. Invalid dimensions.\n";
        return *this;
    }
    Matrix res(rows, m.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < m.cols; ++j) {
            for (int k = 0; k < cols; ++k) {
                res.data[i][j] += data[i][k] * m.data[k][j];
            }
        }
    }
    return res;
}

double Matrix::determinant() const {
    if (rows == 1) return data[0][0];
    if (rows == 2) return data[0][0] * data[1][1] - data[0][1] * data[1][0];

    double det = 0;
    for (int col = 0; col < cols; ++col) {
        Matrix s(rows - 1, cols - 1);
        for (int i = 1; i < rows; ++i) {
            int subCol = 0;
            for (int j = 0; j < cols; ++j) {
                if (j == col) continue;
                s.data[i - 1][subCol++] = data[i][j];
            }
        }
        det += (col % 2 == 0 ? 1 : -1) * data[0][col] * s.determinant();
    }
    return det;
}

double Matrix::operator()(int row, int col) const {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        std::cerr << "Error\n";
        return 0;
    }
    return data[row][col];
}

std::ostream& operator<<(std::ostream& os, const Matrix& m) {
    for (const auto& row : m.data) {
        for (double value : row) {
            os << value << " ";
        }
        os << std::endl;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Matrix& m) {
    std::cout << "Enter " << m.rows * m.cols << " values: " << std::endl;
    for (int i = 0; i < m.rows; ++i) {
        for (int j = 0; j < m.cols; ++j) {
            is >> m.data[i][j];
        }
    }
    return is;
}

int main() {
    Matrix33 A;
    Vector3 x;

    std::cin >> A >> x;

    Vector3 result = computeAx(A, x);
    std::cout << "Result of Ax = " << result << std::endl;

    return 0;
}
