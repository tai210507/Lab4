#include "cSoPhuc.h"
#include <cmath>
#include <limits>

using namespace std;


cSoPhuc::cSoPhuc(double _thuc, double _ao) {
    thuc = _thuc;
    ao = _ao;
}

// Toán tử +
cSoPhuc cSoPhuc::operator+(const cSoPhuc& sp) const {
    return cSoPhuc(thuc + sp.thuc, ao + sp.ao);
}

// Toán tử -
cSoPhuc cSoPhuc::operator-(const cSoPhuc& sp) const {
    return cSoPhuc(thuc - sp.thuc, ao - sp.ao);
}

// Toán tử *
cSoPhuc cSoPhuc::operator*(const cSoPhuc& sp) const {
    return cSoPhuc(thuc * sp.thuc - ao * sp.ao, thuc * sp.ao + ao * sp.thuc);
}

// Toán tử /
cSoPhuc cSoPhuc::operator/(const cSoPhuc& sp) const {
    double mauSo = sp.thuc * sp.thuc + sp.ao * sp.ao;
    if (mauSo == 0) {
        cout << "Loi: Chia cho 0!" << endl;
        return cSoPhuc(0, 0);
    }
    return cSoPhuc((thuc * sp.thuc + ao * sp.ao) / mauSo,
                   (ao * sp.thuc - thuc * sp.ao) / mauSo);
}

// Toán tử ==
bool cSoPhuc::operator==(const cSoPhuc& sp) const {
    return (thuc == sp.thuc && ao == sp.ao);
}

// Toán tử !=
bool cSoPhuc::operator!=(const cSoPhuc& sp) const {
    return !(*this == sp);
}

// Hàm bạn >>
istream& operator>>(istream& is, cSoPhuc& sp) {

    while (true) {
        cout << "  + Nhap phan thuc: ";
        if (is >> sp.thuc) {
            break; // Nếu nhập thành công, thoát vòng lặp
        } else {
            cout << "    -> LOI: Ban vua nhap chu. Vui long nhap SO!\n";
            is.clear(); // Xóa trạng thái lỗi (failbit) của cin
            is.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    while (true) {
        cout << "  + Nhap phan ao: ";
        if (is >> sp.ao) {
            break;
        } else {
            cout << "    -> LOI: Ban vua nhap chu. Vui long nhap SO5!\n";
            is.clear();
            is.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return is;
}

// Hàm bạn <<
ostream& operator<<(ostream& os, const cSoPhuc& sp) {
    if (sp.thuc == 0 && sp.ao == 0) {
        os << 0;
    } else if (sp.thuc == 0) {
        os << sp.ao << "i";
    } else if (sp.ao == 0) {
        os << sp.thuc;
    } else {
        os << sp.thuc << (sp.ao > 0 ? " + " : " - ") << abs(sp.ao) << "i";
    }
    return os;
}
