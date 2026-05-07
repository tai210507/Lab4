#include "CMatrix.h"
#include <iomanip>

using namespace std;


void CMatrix::allocate(int r, int c) {
    rows = r; cols = c;
    if (rows > 0 && cols > 0) {
        data = new double*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new double[cols]();
        }
    } else {
        data = nullptr;
        rows = cols = 0;
    }
}

void CMatrix::deallocate() {
    if (data != nullptr) {
        for (int i = 0; i < rows; i++) delete[] data[i];
        delete[] data;
        data = nullptr;
    }
}

CMatrix::CMatrix(int r, int c) { allocate(r, c); }

CMatrix::CMatrix(const CMatrix& other) {
    allocate(other.rows, other.cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            data[i][j] = other.data[i][j];
}

CMatrix::~CMatrix() { deallocate(); }

CMatrix& CMatrix::operator=(const CMatrix& other) {
    if (this != &other) {
        deallocate();
        allocate(other.rows, other.cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                data[i][j] = other.data[i][j];
    }
    return *this;
}


CMatrix CMatrix::operator+(const CMatrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        cout << "[LOI] Khong the cong 2 ma tran khac kich thuoc!\n";
        return CMatrix();
    }
    CMatrix res(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            res.data[i][j] = data[i][j] + other.data[i][j];
    return res;
}

CMatrix CMatrix::operator-(const CMatrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        cout << "[LOI] Khong the tru 2 ma tran khac kich thuoc!\n";
        return CMatrix();
    }
    CMatrix res(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            res.data[i][j] = data[i][j] - other.data[i][j];
    return res;
}

CMatrix CMatrix::operator*(const CMatrix& other) const {
    if (cols != other.rows) {
        cout << "[LOI] So cot cua MT1 phai bang so dong cua MT2!\n";
        return CMatrix();
    }
    CMatrix res(rows, other.cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < other.cols; j++)
            for (int k = 0; k < cols; k++)
                res.data[i][j] += data[i][k] * other.data[k][j];
    return res;
}


vector<double> CMatrix::operator*(const vector<double>& vec) const {
    if (cols != vec.size()) {
        cout << "[LOI] So cot cua Ma tran phai bang so chieu cua Vector!\n";
        return vector<double>();
    }
    vector<double> res(rows, 0.0);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            res[i] += data[i][j] * vec[j];
        }
    }
    return res;
}


istream& operator>>(istream& is, CMatrix& mat) {
    cout << "  + Nhap so dong: ";
    int r; is >> r;
    cout << "  + Nhap so cot: ";
    int c; is >> c;

    CMatrix temp(r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << "    MT[" << i << "][" << j << "] = ";
            is >> temp.data[i][j];
        }
    }
    mat = temp;
    return is;
}

ostream& operator<<(ostream& os, const CMatrix& mat) {
    if (mat.rows == 0 || mat.cols == 0) {
        os << "(Ma tran rong)\n";
        return os;
    }
    for (int i = 0; i < mat.rows; i++) {
        os << "| ";
        for (int j = 0; j < mat.cols; j++) {
            os << setw(6) << mat.data[i][j] << " ";
        }
        os << "|\n";
    }
    return os;
}
