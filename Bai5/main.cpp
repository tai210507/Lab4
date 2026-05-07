#include <iostream>
#include "cDaThuc.h"

using namespace std;

int main() {

    cDaThuc A, B;

    cout << "[1] NHAP DA THUC A(x)\n";
    cin >> A;
    cout << "=> A(x) = " << A << "\n\n";

    cout << "[2] NHAP DA THUC B(x)\n";
    cin >> B;
    cout << "=> B(x) = " << B << "\n\n";

    cout << "[3] CAC PHEP TOAN TREN DA THUC\n";
    cout << "A(x) + B(x) = " << A + B << "\n";
    cout << "A(x) - B(x) = " << A - B << "\n";
    cout << "A(x) * B(x) = " << A * B << "\n\n";

    cout << "[4] TINH GIA TRI DA THUC TAI DIEM x\n";
    double x;
    cout << "Nhap gia tri x: ";
    cin >> x;
    cout << "=> A(" << x << ") = " << A.tinhGiaTri(x) << "\n";
    cout << "=> B(" << x << ") = " << B.tinhGiaTri(x) << "\n";

    return 0;
}
