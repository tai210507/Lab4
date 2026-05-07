#include "cDaThuc.h"
#include <cmath>
#include <algorithm>

using namespace std;




cDaThuc::cDaThuc(int n) {
    bac = (n >= 0) ? n : 0;
    heSo = new double[bac + 1];
    for (int i = 0; i <= bac; i++) {
        heSo[i] = 0.0;
    }
}


cDaThuc::cDaThuc(const cDaThuc& other) {
    bac = other.bac;
    heSo = new double[bac + 1];
    for (int i = 0; i <= bac; i++) {
        heSo[i] = other.heSo[i];
    }
}


cDaThuc::~cDaThuc() {
    delete[] heSo;
}


cDaThuc& cDaThuc::operator=(const cDaThuc& other) {
    if (this != &other) {
        delete[] heSo;
        bac = other.bac;
        heSo = new double[bac + 1];
        for (int i = 0; i <= bac; i++) {
            heSo[i] = other.heSo[i];
        }
    }
    return *this;
}


cDaThuc cDaThuc::operator+(const cDaThuc& other) const {
    int maxBac = max(bac, other.bac);
    cDaThuc ketQua(maxBac);

    for (int i = 0; i <= maxBac; i++) {
        double heSo1 = (i <= bac) ? heSo[i] : 0;
        double heSo2 = (i <= other.bac) ? other.heSo[i] : 0;
        ketQua.heSo[i] = heSo1 + heSo2;
    }
    return ketQua;
}

cDaThuc cDaThuc::operator-(const cDaThuc& other) const {
    int maxBac = max(bac, other.bac);
    cDaThuc ketQua(maxBac);

    for (int i = 0; i <= maxBac; i++) {
        double heSo1 = (i <= bac) ? heSo[i] : 0;
        double heSo2 = (i <= other.bac) ? other.heSo[i] : 0;
        ketQua.heSo[i] = heSo1 - heSo2;
    }
    return ketQua;
}

cDaThuc cDaThuc::operator*(const cDaThuc& other) const {
    int newBac = bac + other.bac;
    cDaThuc ketQua(newBac);

    for (int i = 0; i <= bac; i++) {
        for (int j = 0; j <= other.bac; j++) {

            ketQua.heSo[i + j] += heSo[i] * other.heSo[j];
        }
    }
    return ketQua;
}

double cDaThuc::tinhGiaTri(double x) const {
    double ketQua = 0;
    for (int i = 0; i <= bac; i++) {
        ketQua += heSo[i] * pow(x, i);
    }
    return ketQua;
}



istream& operator>>(istream& is, cDaThuc& dt) {
    cout << "  + Nhap bac cua da thuc: ";
    int n;
    is >> n;


    cDaThuc temp(n);

    for (int i = temp.bac; i >= 0; i--) {
        cout << "    - Nhap he so cua x^" << i << ": ";
        is >> temp.heSo[i];
    }

    dt = temp;
    return is;
}

ostream& operator<<(ostream& os, const cDaThuc& dt) {
    bool laDaThucKhong = true;


    for (int i = dt.bac; i >= 0; i--) {
        double hs = dt.heSo[i];
        if (hs == 0) continue;

        laDaThucKhong = false;


        if (hs > 0 && i != dt.bac) os << " + ";
        if (hs < 0) {
            if (i == dt.bac) os << "-";
            else os << " - ";
        }


        double absHs = abs(hs);
        if (absHs != 1 || i == 0) os << absHs;


        if (i > 0) os << "x";
        if (i > 1) os << "^" << i;
    }

    if (laDaThucKhong) os << "0";
    return os;
}
