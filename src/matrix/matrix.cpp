/*
 * matrix.cpp
 */

#include <stdexcept>
#include <iostream>
#include <iomanip>
#include "matrix.h"

#define EPS 1e-10

using std::domain_error;
using std::endl;
using std::istream;
using std::ostream;

using namespace std;

/* PUBLIC MEMBER FUNCTIONS
 ********************************/

Matrix::Matrix(int rows, int cols) : rows_(rows), cols_(cols)
{
    allocSpace();
    for (int i = 0; i < rows_; ++i)
    {
        for (int j = 0; j < cols_; ++j)
        {
            p[i][j] = 0;
        }
    }
}

Matrix::Matrix(float **a, int rows, int cols) : rows_(rows), cols_(cols)
{
    allocSpace();
    for (int i = 0; i < rows_; ++i)
    {
        for (int j = 0; j < cols_; ++j)
        {
            p[i][j] = a[i][j];
        }
    }
}

Matrix::Matrix() : rows_(1), cols_(1)
{
    allocSpace();
    p[0][0] = 0;
}

Matrix::~Matrix()
{
    for (int i = 0; i < rows_; ++i)
    {
        delete[] p[i];
    }
    delete[] p;
}

Matrix::Matrix(const Matrix &m) : rows_(m.rows_), cols_(m.cols_)
{
    allocSpace();
    for (int i = 0; i < rows_; ++i)
    {
        for (int j = 0; j < cols_; ++j)
        {
            p[i][j] = m.p[i][j];
        }
    }
}

Matrix &Matrix::operator=(const Matrix &m)
{
    if (this == &m)
    {
        return *this;
    }

    if (rows_ != m.rows_ || cols_ != m.cols_)
    {
        for (int i = 0; i < rows_; ++i)
        {
            delete[] p[i];
        }
        delete[] p;

        rows_ = m.rows_;
        cols_ = m.cols_;
        allocSpace();
    }

    for (int i = 0; i < rows_; ++i)
    {
        for (int j = 0; j < cols_; ++j)
        {
            p[i][j] = m.p[i][j];
        }
    }
    return *this;
}

Matrix &Matrix::operator+=(const Matrix &m)
{
    for (int i = 0; i < rows_; ++i)
    {
        for (int j = 0; j < cols_; ++j)
        {
            p[i][j] += m.p[i][j];
        }
    }
    return *this;
}

Matrix &Matrix::operator-=(const Matrix &m)
{
    for (int i = 0; i < rows_; ++i)
    {
        for (int j = 0; j < cols_; ++j)
        {
            p[i][j] -= m.p[i][j];
        }
    }
    return *this;
}

Matrix &Matrix::operator*=(const Matrix &m)
{
    Matrix temp(rows_, m.cols_);
    for (int i = 0; i < temp.rows_; ++i)
    {
        for (int j = 0; j < temp.cols_; ++j)
        {
            for (int k = 0; k < cols_; ++k)
            {
                temp.p[i][j] += (p[i][k] * m.p[k][j]);
            }
        }
    }
    return (*this = temp);
}

Matrix &Matrix::operator*=(float num)
{
    for (int i = 0; i < rows_; ++i)
    {
        for (int j = 0; j < cols_; ++j)
        {
            p[i][j] *= num;
        }
    }
    return *this;
}

Matrix &Matrix::operator/=(float num)
{
    for (int i = 0; i < rows_; ++i)
    {
        for (int j = 0; j < cols_; ++j)
        {
            p[i][j] /= num;
        }
    }
    return *this;
}

Matrix Matrix::operator^(int num)
{
    Matrix temp(*this);
    return expHelper(temp, num);
}

Vector2 Matrix::operator*(Vector2 v)
{
    Matrix temp(3, 1);
    temp.p[0][0] = v.x;
    temp.p[1][0] = v.y;
    temp.p[2][0] = 1;
    Matrix temp2 = (*this * temp);
    return Vector2(temp2.p[0][0], temp2.p[1][0]);
}

void Matrix::swapRows(int r1, int r2)
{
    float *temp = p[r1];
    p[r1] = p[r2];
    p[r2] = temp;
}

Matrix Matrix::transpose()
{
    Matrix ret(cols_, rows_);
    for (int i = 0; i < rows_; ++i)
    {
        for (int j = 0; j < cols_; ++j)
        {
            ret.p[j][i] = p[i][j];
        }
    }
    return ret;
}

/* STATIC CLASS FUNCTIONS
 ********************************/

Matrix Matrix::createIdentity(int size)
{
    Matrix temp(size, size);
    for (int i = 0; i < temp.rows_; ++i)
    {
        for (int j = 0; j < temp.cols_; ++j)
        {
            if (i == j)
            {
                temp.p[i][j] = 1;
            }
            else
            {
                temp.p[i][j] = 0;
            }
        }
    }
    return temp;
}

Matrix Matrix::scale(float sx, float sy)
{
    Matrix temp = createIdentity(3);
    temp(0, 0) = sx;
    temp(1, 1) = sy;
    return temp;
}

Matrix Matrix::translate(float tx, float ty)
{
    Matrix temp = createIdentity(3);
    temp(0, 2) = tx;
    temp(1, 2) = ty;
    return temp;
}

Matrix Matrix::rotate(float angle)
{
    angle = angle * (M_PI / 180);
    Matrix temp = createIdentity(3);
    temp(0, 0) = cos(angle);
    temp(0, 1) = -sin(angle);
    temp(1, 0) = sin(angle);
    temp(1, 1) = cos(angle);
    return temp;
}

// functions on VECTORS
float Matrix::dotProduct(Matrix a, Matrix b)
{
    float sum = 0;
    for (int i = 0; i < a.rows_; ++i)
    {
        sum += (a(i, 0) * b(i, 0));
    }
    return sum;
}

void Matrix::print()
{
    for (int i = 0; i < rows_; ++i)
    {
        for (int j = 0; j < cols_; ++j)
        {
            cout << setw(10) << fixed << setprecision(2) << p[i][j] << " ";
        }
        cout << endl;
    }
}

/* PRIVATE HELPER FUNCTIONS
 ********************************/

void Matrix::allocSpace()
{
    p = new float *[rows_];
    for (int i = 0; i < rows_; ++i)
    {
        p[i] = new float[cols_];
    }
}

Matrix Matrix::expHelper(const Matrix &m, int num)
{
    if (num == 0)
    {
        return createIdentity(m.rows_);
    }
    else if (num == 1)
    {
        return m;
    }
    else if (num % 2 == 0)
    { // num is even
        return expHelper(m * m, num / 2);
    }
    else
    { // num is odd
        return m * expHelper(m * m, (num - 1) / 2);
    }
}

/* NON-MEMBER FUNCTIONS
 ********************************/

Matrix operator+(const Matrix &m1, const Matrix &m2)
{
    Matrix temp(m1);
    return (temp += m2);
}

Matrix operator-(const Matrix &m1, const Matrix &m2)
{
    Matrix temp(m1);
    return (temp -= m2);
}

Matrix operator*(const Matrix &m1, const Matrix &m2)
{
    Matrix temp(m1);
    return (temp *= m2);
}

Matrix operator*(const Matrix &m, float num)
{
    Matrix temp(m);
    return (temp *= num);
}

Matrix operator*(float num, const Matrix &m)
{
    return (m * num);
}

Matrix operator/(const Matrix &m, float num)
{
    Matrix temp(m);
    return (temp /= num);
}
