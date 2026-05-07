#include "CDate.h"
#include <iomanip>
#include <limits>
#include <cmath>

using namespace std;



bool CDate::laNamNhuan(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int CDate::soNgayTrongThang(int m, int y) const {
    int daysInMonths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && laNamNhuan(y)) return 29;
    return daysInMonths[m];
}


int CDate::tinhTongSoNgay() const {
    int namAo = nam;
    if (thang <= 2) namAo--;

    int soNamNhuan = namAo / 4 - namAo / 100 + namAo / 400;

    int tongNgay = nam * 365 + ngay;
    for (int i = 1; i < thang; i++) {
        tongNgay += soNgayTrongThang(i, nam);
    }
    tongNgay += soNamNhuan;
    return tongNgay;
}

void CDate::chuanHoa() {
    if (nam < 1) nam = 1;
    if (thang < 1) thang = 1;
    if (thang > 12) thang = 12;

    int maxNgay = soNgayTrongThang(thang, nam);
    if (ngay < 1) ngay = 1;
    if (ngay > maxNgay) ngay = maxNgay;
}


CDate::CDate(int d, int m, int y) : ngay(d), thang(m), nam(y) {
    chuanHoa();
}


CDate CDate::operator+(int days) const {
    CDate result = *this;
    while (days > 0) {
        int ngayConLaiTrongThang = soNgayTrongThang(result.thang, result.nam) - result.ngay;
        if (days <= ngayConLaiTrongThang) {
            result.ngay += days;
            break;
        } else {
            days -= (ngayConLaiTrongThang + 1);
            result.ngay = 1;
            result.thang++;
            if (result.thang > 12) {
                result.thang = 1;
                result.nam++;
            }
        }
    }
    return result;
}

CDate CDate::operator-(int days) const {
    CDate result = *this;
    while (days > 0) {
        if (days < result.ngay) {
            result.ngay -= days;
            break;
        } else {
            days -= result.ngay;
            result.thang--;
            if (result.thang < 1) {
                result.thang = 12;
                result.nam--;
            }
            result.ngay = soNgayTrongThang(result.thang, result.nam);
        }
    }
    return result;
}


int CDate::operator-(const CDate& other) const {

    return abs(this->tinhTongSoNgay() - other.tinhTongSoNgay());
}


CDate& CDate::operator++() {
    *this = *this + 1;
    return *this;
}

CDate CDate::operator++(int) {
    CDate temp = *this;
    *this = *this + 1;
    return temp;
}

CDate& CDate::operator--() {
    *this = *this - 1;
    return *this;
}

CDate CDate::operator--(int) {
    CDate temp = *this;
    *this = *this - 1;
    return temp;
}


istream& operator>>(istream& is, CDate& d) {
    while (true) {
        cout << "Nhap Ngay Thang Nam (VD: 15 8 2026): ";
        if (is >> d.ngay >> d.thang >> d.nam) {
            d.chuanHoa();
            break;
        }
        cout << "  -> LOI: Vui long nhap SO!\n";
        is.clear();
        is.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return is;
}

ostream& operator<<(ostream& os, const CDate& d) {
    os << setfill('0') << setw(2) << d.ngay << "/"
       << setfill('0') << setw(2) << d.thang << "/"
       << d.nam;
    return os;
}
