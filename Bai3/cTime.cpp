#include "CTime.h"
#include <iomanip>
#include <limits>

using namespace std;


void CTime::chuanHoa() {
    // Quy đổi tất cả ra tổng số giây
    long tongGiay = gio * 3600 + phut * 60 + giay;

    // Xử lý trường hợp lùi qua 0h đêm
    tongGiay = (tongGiay % 86400 + 86400) % 86400;

    // Chia ngược lại ra giờ, phút, giây
    gio = tongGiay / 3600;
    phut = (tongGiay % 3600) / 60;
    giay = tongGiay % 60;
}

// Constructor
CTime::CTime(int h, int m, int s) : gio(h), phut(m), giay(s) {
    chuanHoa();
}

// CTime + số nguyên (giây)
CTime CTime::operator+(int s) const {
    return CTime(gio, phut, giay + s);
}

// CTime - số nguyên (giây)
CTime CTime::operator-(int s) const {
    return CTime(gio, phut, giay - s);
}

//  Tiền tố: ++t
CTime& CTime::operator++() {
    giay++;
    chuanHoa();
    return *this;
}

CTime& CTime::operator--() {
    giay--;
    chuanHoa();
    return *this;
}

//  Hậu tố: t++
CTime CTime::operator++(int) {
    CTime temp = *this;
    giay++;
    chuanHoa();
    return temp;
}

CTime CTime::operator--(int) {
    CTime temp = *this;
    giay--;
    chuanHoa();
    return temp;
}


istream& operator>>(istream& is, CTime& t) {
    while (true) {
        cout << "Nhap Giay, Phut, Gio (Cach nhau bang khoang trang. VD: 15 30 14): ";
        if (is >> t.giay >> t.phut >> t.gio) {
            t.chuanHoa();
            break;
        }
        cout << "  -> LOI: Vui long nhap SO nguyen!\n";
        is.clear();
        is.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return is;
}

ostream& operator<<(ostream& os, const CTime& t) {
    // In định dạng hh:mm:ss (Thêm số 0 vào trước nếu < 10)
    os << setfill('0') << setw(2) << t.gio << ":"
       << setfill('0') << setw(2) << t.phut << ":"
       << setfill('0') << setw(2) << t.giay;
    return os;
}
