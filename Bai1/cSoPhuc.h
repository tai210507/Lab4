#ifndef CSOPHUC_H
#define CSOPHUC_H

#include <iostream>

class cSoPhuc {
private:
    double thuc;
    double ao;

public:

    cSoPhuc(double _thuc = 0, double _ao = 0);

    // Các phép toán số học
    cSoPhuc operator+(const cSoPhuc& sp) const;
    cSoPhuc operator-(const cSoPhuc& sp) const;
    cSoPhuc operator*(const cSoPhuc& sp) const;
    cSoPhuc operator/(const cSoPhuc& sp) const;

    // Các phép toán so sánh
    bool operator==(const cSoPhuc& sp) const;
    bool operator!=(const cSoPhuc& sp) const;

    // Phép toán nhập/xuất dữ liệu
    friend std::istream& operator>>(std::istream& is, cSoPhuc& sp);
    friend std::ostream& operator<<(std::ostream& os, const cSoPhuc& sp);
};

#endif
