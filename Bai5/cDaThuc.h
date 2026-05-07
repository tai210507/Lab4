#ifndef CDATHUC_H
#define CDATHUC_H

#include <iostream>

class cDaThuc {
private:
    int bac;
    double* heSo;

public:

    cDaThuc(int n = 0);
    cDaThuc(const cDaThuc& other);
    ~cDaThuc();
    cDaThuc& operator=(const cDaThuc& other);


    cDaThuc operator+(const cDaThuc& other) const;
    cDaThuc operator-(const cDaThuc& other) const;
    cDaThuc operator*(const cDaThuc& other) const;


    double tinhGiaTri(double x) const;


    friend std::istream& operator>>(std::istream& is, cDaThuc& dt);
    friend std::ostream& operator<<(std::ostream& os, const cDaThuc& dt);
};

#endif
