#include <iostream>
#include <iomanip>
#include "CDate.h"

using namespace std;

// Hàm giải quyết bài toán ngân hàng
void baiToanNganHang() {
    cout << "\nUNG DUNG TINH LAI SUAT TIEN GUI NGAN HANG\n";


    CDate ngayGui, ngayRut;
    double soTienGui, laiSuatNam;

    cout << "[1] THONG TIN THOI GIAN\n";
    cout << "- Nhap ngay bat dau gui tien:\n  -> ";
    cin >> ngayGui;

    cout << "- Nhap ngay rut tien:\n  -> ";
    cin >> ngayRut;


    int soNgayThucTe = ngayRut - ngayGui;

    cout << "\n[2] THONG TIN TAI CHINH\n";
    cout << "- Nhap so tien gui (VND): ";
    cin >> soTienGui;
    cout << "- Nhap lai suat nam (%/nam): ";
    cin >> laiSuatNam;

    // Công thức tính lãi suất theo số ngày thực tế
    // Tiền lãi = Tiền gốc * (Lãi suất / 100) * (Số ngày gửi / 365)
    double tienLai = soTienGui * (laiSuatNam / 100.0) * (soNgayThucTe / 365.0);
    double tongTien = soTienGui + tienLai;

    cout << "\n KET QUA \n";
    cout << "Ngay gui: " << ngayGui << endl;
    cout << "Ngay rut: " << ngayRut << endl;
    cout << "So ngay gui: " << soNgayThucTe << " ngay\n";
    cout << "Tien lai nhan duoc: " << fixed << setprecision(0) << tienLai << " VND\n";
    cout << "Tong tien thu ve: " << fixed << setprecision(0) << tongTien << " VND\n";
}

int main() {
    cout << " TEST CAC PHEP TOAN TREN CDATE \n";
    CDate d1(28, 2, 2024); // Năm nhuận
    cout << "Ngay ban dau d1: " << d1 << endl;

    cout << "1. ++d1 (Tang 1 ngay): " << ++d1 << " (Chuyen tu 28/2 sang 29/2 vi la nam nhuan)\n";
    cout << "2. d1 + 30 (Cong them 30 ngay): " << d1 + 30 << "\n";

    CDate d2(1, 1, 2025);
    cout << "3. Khoang cach giua d1 (" << d1 << ") va d2 (" << d2 << ") la: " << d2 - d1 << " ngay\n";

    // Gọi ứng dụng ngân hàng
    baiToanNganHang();

    return 0;
}
