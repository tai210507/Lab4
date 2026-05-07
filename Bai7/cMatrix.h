#ifndef CMATRIX_H
#define CMATRIX_H

#include <iostream>
#include <vector>

class CMatrix {
private:
    int rows;
    int cols;
    double** data;

    void allocate(int r, int c);
    void deallocate();

public:
    CMatrix(int r = 0, int c = 0);
    CMatrix(const CMatrix& other);
    ~CMatrix();
    CMatrix& operator=(const CMatrix& other);

    CMatrix operator+(const CMatrix& other) const;
    CMatrix operator-(const CMatrix& other) const;
    CMatrix operator*(const CMatrix& other) const;


    std::vector<double> operator*(const std::vector<double>& vec) const;

    friend std::istream& operator>>(std::istream& is, CMatrix& mat);
    friend std::ostream& operator<<(std::ostream& os, const CMatrix& mat);
};

#endif
