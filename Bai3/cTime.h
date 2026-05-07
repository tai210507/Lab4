#ifndef CTIME_H
#define CTIME_H

#include <iostream>

class CTime {
private:
    int gio;
    int phut;
    int giay;


    void chuanHoa();

public:
    CTime(int h = 0, int m = 0, int s = 0);

    // Phép toán cộng/trừ với số nguyên giây
    CTime operator+(int s) const;
    CTime operator-(int s) const;

    // Phép toán ++, -- (
    CTime& operator++();
    CTime& operator--();

    // Phép toán ++, --
    CTime operator++(int);
    CTime operator--(int);

    // Phép toán xuất/nhập
    friend std::istream& operator>>(std::istream& is, CTime& t);
    friend std::ostream& operator<<(std::ostream& os, const CTime& t);
};

#endif
