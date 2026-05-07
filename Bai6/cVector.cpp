#include "CVector.h"

using namespace std;


CVector::CVector(int size) {
    n = (size > 0) ? size : 0;
    if (n > 0) {
        v = new double[n];
        for (int i = 0; i < n; i++) v[i] = 0.0;
    } else {
        v = nullptr;
    }
}

CVector::CVector(const CVector& other) {
    n = other.n;
    if (n > 0) {
        v = new double[n];
        for (int i = 0; i < n; i++) v[i] = other.v[i];
    } else {
        v = nullptr;
    }
}

CVector::~CVector() {
    delete[] v;
}

CVector& CVector::operator=(const CVector& other) {
    if (this != &other) {
        delete[] v;
        n = other.n;
        if (n > 0) {
            v = new double[n];
            for (int i = 0; i < n; i++) v[i] = other.v[i];
        } else {
            v = nullptr;
        }
    }
    return *this;
}


CVector CVector::operator+(const CVector& other) const {
    if (n != other.n) {
        cout << "[LOI] Khong the cong hai vector khac so chieu!\n";
        return CVector(0);
    }
    CVector result(n);
    for (int i = 0; i < n; i++) {
        result.v[i] = v[i] + other.v[i];
    }
    return result;
}

CVector CVector::operator-(const CVector& other) const {
    if (n != other.n) {
        cout << "[LOI] Khong the tru hai vector khac so chieu!\n";
        return CVector(0);
    }
    CVector result(n);
    for (int i = 0; i < n; i++) {
        result.v[i] = v[i] - other.v[i];
    }
    return result;
}

CVector CVector::operator*(double scalar) const {
    CVector result(n);
    for (int i = 0; i < n; i++) {
        result.v[i] = v[i] * scalar;
    }
    return result;
}

double CVector::operator*(const CVector& other) const {
    if (n != other.n) {
        cout << "[LOI] Khong the nhan vo huong hai vector khac so chieu!\n";
        return 0.0;
    }
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        result += v[i] * other.v[i];
    }
    return result;
}

CVector operator*(double scalar, const CVector& vec) {
    return vec * scalar;
}


istream& operator>>(istream& is, CVector& vec) {
    cout << "  + Nhap so chieu cua vector: ";
    int size;
    is >> size;

    CVector temp(size);
    for (int i = 0; i < temp.n; i++) {
        cout << "    - Toa do thu " << i + 1 << ": ";
        is >> temp.v[i];
    }

    vec = temp;
    return is;
}

ostream& operator<<(ostream& os, const CVector& vec) {
    if (vec.n == 0) {
        os << "(Rong)";
        return os;
    }
    os << "(";
    for (int i = 0; i < vec.n; i++) {
        os << vec.v[i];
        if (i < vec.n - 1) os << ", ";
    }
    os << ")";
    return os;
}
