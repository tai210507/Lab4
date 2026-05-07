#ifndef CVECTOR_H
#define CVECTOR_H

#include <iostream>

class CVector {
private:
    int n;
    double* v;
public:

    CVector(int size = 0);
    CVector(const CVector& other);
    ~CVector();
    CVector& operator=(const CVector& other);

    CVector operator+(const CVector& other) const;
    CVector operator-(const CVector& other) const;

    // Nhân vô hướng (Vector * Số)
    CVector operator*(double scalar) const;

    // Tích vô hướng (Vector * Vector -> Số thực)
    double operator*(const CVector& other) const;

    friend CVector operator*(double scalar, const CVector& vec);

    // Xuất / Nhập
    friend std::istream& operator>>(std::istream& is, CVector& vec);
    friend std::ostream& operator<<(std::ostream& os, const CVector& vec);
};

#endif
