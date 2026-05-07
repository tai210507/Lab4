#ifndef CPHANSO_H
#define CPHANSO_H

#include <iostream>

class cPhanSo {
private:
    int tuSo;
    int mauSo;


    int UCLN(int a, int b) const;
    void rutGon();

public:
    // Phương thức thiết lập cho phép 1 số nguyên thành phân số
    cPhanSo(int _tu = 0, int _mau = 1);

    // Các phép toán số học
    cPhanSo operator+(const cPhanSo& ps) const;
    cPhanSo operator-(const cPhanSo& ps) const;
    cPhanSo operator*(const cPhanSo& ps) const;
    cPhanSo operator/(const cPhanSo& ps) const;

    // Các phép toán so sánh
    bool operator==(const cPhanSo& ps) const;
    bool operator>(const cPhanSo& ps) const;
    bool operator<(const cPhanSo& ps) const;

    // Phép toán nhập/xuất dữ liệu
    friend std::istream& operator>>(std::istream& is, cPhanSo& ps);
    friend std::ostream& operator<<(std::ostream& os, const cPhanSo& ps);
};

#endif
