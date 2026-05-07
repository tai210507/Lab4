#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <thread>
#include <chrono>
#include "CTime.h"

using namespace std;

int main() {
    CTime t;



    cin >> t;
    cout << "\nThoi gian ban vua nhap: " << t << endl;

    //  Cộng, trừ thêm một số nguyên giây
    cout << "\n Thuc hien phep toan " << endl;
    cout << "1. Cong them 15 giay (t + 15) : " << t + 15 << endl;
    cout << "2. Tru di 20 giay (t - 20)    : " << t - 20 << endl;

    //  Phép toán ++, --
    cout << "3. Toan tu ++ tien to (++t)   : " << ++t << endl;
    cout << "4. Toan tu ++ hau to (t++)    : " << t++ << " (In ra gia tri truoc khi tang)" << endl;
    cout << "   -> Gia tri cua t hien tai  : " << t << endl;

    cout << "\nChuong trinh se chuyen sang che do Dong Ho sau 3 giay..." << endl;
    this_thread::sleep_for(chrono::seconds(3));



    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    // Vòng lặp chạy đồng hồ vô hạn
    while (true) {

        cout << "\r" << setfill(' ') << setw(100) << "DONG HO: " << t << flush;

        t++;
        this_thread::sleep_for(chrono::seconds(1));
    }

    return 0;
}
