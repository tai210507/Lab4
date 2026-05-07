#include <iostream>
#include "cSoPhuc.h"

using namespace std;

int main() {
    // Test constructor
    cSoPhuc sp1(3, 4);
    cSoPhuc sp2(5);
    cSoPhuc sp3;

    cout << " Khoi tao bang Constructor " << endl;
    cout << "sp1 = " << sp1 << endl;
    cout << "sp2 = " << sp2 << endl;

    // Test nhập/xuất
    cout << "\n Nhap so phuc sp3" << endl;
    cin >> sp3;
    cout << "sp3 vua nhap la: " << sp3 << endl;

    // Test các phép toán
    cout << "\n Test cac phep toan tren sp1 va sp3 " << endl;
    cout << "sp1 + sp3 = " << sp1 + sp3 << endl;
    cout << "sp1 - sp3 = " << sp1 - sp3 << endl;
    cout << "sp1 * sp3 = " << sp1 * sp3 << endl;
    cout << "sp1 / sp3 = " << sp1 / sp3 << endl;

    // Test so sánh
    cout << "\n Test so sanh " << endl;
    if (sp1 == sp3) {
        cout << "sp1 bang sp3" << endl;
    } else {
        cout << "sp1 khac sp3" << endl;
    }

    return 0;
}
