#include <iostream>
#include "CVector.h"

using namespace std;

int main() {

    CVector u, v;

    cout << "[1] NHAP VECTOR u\n";
    cin >> u;
    cout << "=> u = " << u << "\n\n";

    cout << "[2] NHAP VECTOR v\n";
    cin >> v;
    cout << "=> v = " << v << "\n\n";

    cout << "[3] CAC PHEP TOAN TREN VECTOR\n";
    cout << "u + v = " << u + v << "\n";
    cout << "u - v = " << u - v << "\n";

    cout << "\n[4] NHAN VO HUONG (Voi 1 so thuc)\n";
    cout << "u * 3 = " << u * 3 << "\n";
    cout << "5 * v = " << 5 * v << " (Test tinh giao hoan)\n";

    cout << "\n[5] TICH VO HUONG \n";
    cout << "u * v = " << u * v << "\n";

    return 0;
}
