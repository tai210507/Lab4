#include <iostream>
#include "cPhanSo.h"

using namespace std;

int main() {
    // Test constructor
    cPhanSo ps1(1, 2);     // Phân số bình thường: 1/2
    cPhanSo ps2(5);        // Số nguyên đóng vai trò phân số: 5/1 (khi in ra sẽ là 5)
    cPhanSo ps3;           // Mặc định: 0/1 (khi in ra sẽ là 0)

    cout << " Khoi tao bang Constructor " << endl;
    cout << "ps1 = " << ps1 << endl;
    cout << "ps2 = " << ps2 << endl;

    // Test nhập/xuất
    cout << "\n Nhap phan so ps3 " << endl;
    cin >> ps3;
    cout << "ps3 vua nhap va rut gon la: " << ps3 << endl;

    // Test các phép toán
    cout << "\n Test cac phep toan tren ps1 (" << ps1 << ") va ps3 (" << ps3 << ") " << endl;
    cout << "ps1 + ps3 = " << ps1 + ps3 << endl;
    cout << "ps1 - ps3 = " << ps1 - ps3 << endl;
    cout << "ps1 * ps3 = " << ps1 * ps3 << endl;
    cout << "ps1 / ps3 = " << ps1 / ps3 << endl;

    // Test so sánh
    cout << "\n Test so sanh " << endl;
    if (ps1 == ps3) {
        cout << "ps1 bang ps3" << endl;
    } else if (ps1 > ps3) {
        cout << "ps1 lon hon ps3" << endl;
    } else if (ps1 < ps3) {
        cout << "ps1 nho hon ps3" << endl;
    }

    return 0;
}
