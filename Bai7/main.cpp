#include <iostream>
#include <vector>
#include "CMatrix.h"

using namespace std;

int main() {

    CMatrix A, B;

    cout << "[1] NHAP MA TRAN A\n";
    cin >> A;
    cout << "=> Ma tran A:\n" << A << "\n";

    cout << "[2] NHAP MA TRAN B\n";
    cin >> B;
    cout << "=> Ma tran B:\n" << B << "\n";

    cout << "[3] TICH HAI MA TRAN (A * B) =\n" << A * B << "\n";

    cout << "[4] NHAN MA TRAN A VOI MOT VECTOR TOAN HOC\n";

    int size;
    cout << "Nhap so chieu cua vector v: ";
    cin >> size;

    vector<double> v(size);
    for (int i = 0; i < size; i++) {
        cout << "  - Nhap toa do thu " << i + 1 << ": ";
        cin >> v[i];
    }


    vector<double> ketQua = A * v;

    cout << "=> Ket qua (A * v) = ( ";
    for (int i = 0; i < ketQua.size(); i++) {
        cout << ketQua[i] << " ";
    }
    cout << ")\n";

    return 0;
}
