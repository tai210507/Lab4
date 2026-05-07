#include "cPhanSo.h"
#include <cmath>
#include <limits>

using namespace std;

// Tìm Ước chung lớn nhất
int cPhanSo::UCLN(int a, int b) const {
    a = abs(a); b = abs(b);
    if (b == 0) return a;
    return UCLN(b, a % b);
}

// Rút gọn và chuẩn hóa dấu
void cPhanSo::rutGon() {
    if (mauSo == 0) return;
    int ucln = UCLN(tuSo, mauSo);
    tuSo /= ucln;
    mauSo /= ucln;

    // Đảm bảo mẫu số luôn dương
    if (mauSo < 0) {
        tuSo = -tuSo;
        mauSo = -mauSo;
    }
}

// Constructor
cPhanSo::cPhanSo(int _tu, int _mau) {
    tuSo = _tu;
    if (_mau == 0) {
        cout << "  [Canh bao] Mau so khong the bang 0. Tu dong gan bang 1.\n";
        mauSo = 1;
    } else {
        mauSo = _mau;
    }
    rutGon();
}

//  Phép toán số học
cPhanSo cPhanSo::operator+(const cPhanSo& ps) const {
    return cPhanSo(tuSo * ps.mauSo + ps.tuSo * mauSo, mauSo * ps.mauSo);
}

cPhanSo cPhanSo::operator-(const cPhanSo& ps) const {
    return cPhanSo(tuSo * ps.mauSo - ps.tuSo * mauSo, mauSo * ps.mauSo);
}

cPhanSo cPhanSo::operator*(const cPhanSo& ps) const {
    return cPhanSo(tuSo * ps.tuSo, mauSo * ps.mauSo);
}

cPhanSo cPhanSo::operator/(const cPhanSo& ps) const {
    if (ps.tuSo == 0) {
        cout << "  [Loi] Khong the chia cho phan so 0! Tra ve 0/1.\n";
        return cPhanSo(0, 1);
    }
    return cPhanSo(tuSo * ps.mauSo, mauSo * ps.tuSo);
}

//  Phép toán so sánh
bool cPhanSo::operator==(const cPhanSo& ps) const {

    return (tuSo * ps.mauSo == ps.tuSo * mauSo);
}

bool cPhanSo::operator>(const cPhanSo& ps) const {
    return (tuSo * ps.mauSo > ps.tuSo * mauSo);
}

bool cPhanSo::operator<(const cPhanSo& ps) const {
    return (tuSo * ps.mauSo < ps.tuSo * mauSo);
}


istream& operator>>(istream& is, cPhanSo& ps) {
    // Nhập tử số an toàn
    while (true) {
        cout << "  + Nhap tu so: ";
        if (is >> ps.tuSo) break;
        cout << "    -> LOI: Vui long nhap SO NGUYEN!\n";
        is.clear();
        is.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Nhập mẫu số an toàn & cấm số 0
    while (true) {
        cout << "  + Nhap mau so: ";
        if (is >> ps.mauSo) {
            if (ps.mauSo != 0) break;
            cout << "    -> LOI: Mau so phai khac 0!\n";
        } else {
            cout << "    -> LOI: Vui long nhap SO NGUYEN!\n";
            is.clear();
            is.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    ps.rutGon();
    return is;
}

ostream& operator<<(ostream& os, const cPhanSo& ps) {
    if (ps.tuSo == 0) {
        os << 0;
    } else if (ps.mauSo == 1) {
        os << ps.tuSo;
    } else {
        os << ps.tuSo << "/" << ps.mauSo;
    }
    return os;
}
