#ifndef CDATE_H
#define CDATE_H

#include <iostream>

class CDate {
private:
    int ngay;
    int thang;
    int nam;

    bool laNamNhuan(int y) const;
    int soNgayTrongThang(int m, int y) const;


    int tinhTongSoNgay() const;


    void chuanHoa();

public:
    CDate(int d = 1, int m = 1, int y = 2026);

    // Cộng/Trừ thêm một số ngày (trả về ngày mới)
    CDate operator+(int days) const;
    CDate operator-(int days) const;

    // Khoảng cách giữa 2 CDate (trả về số nguyên)
    int operator-(const CDate& other) const;

    // Các phép toán ++, --
    CDate& operator++();
    CDate operator++(int);
    CDate& operator--();
    CDate operator--(int);

    // Xuất/Nhập
    friend std::istream& operator>>(std::istream& is, CDate& d);
    friend std::ostream& operator<<(std::ostream& os, const CDate& d);
};

#endif
