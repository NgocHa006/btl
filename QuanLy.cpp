#include "QuanLy.h"
#include <iostream>
#include <fstream>

using namespace std;

string danhSachMon[MAX_MON];
int soMonHoc = 0;
unordered_map<string, SinhVien> bangBam;

void nhapMonHoc() {
    cout << "Nhap so mon hoc (<= " << MAX_MON << "): ";
    cin >> soMonHoc;
    cin.ignore();

    for (int i = 0; i < soMonHoc; i++) {
        cout << "Ten mon " << i + 1 << ": ";
        getline(cin, danhSachMon[i]);
    }
}

void themSinhVien() {
    SinhVien sv;
    cout << "Ma SV: ";
    cin >> sv.maSV;

    if (bangBam.count(sv.maSV)) {
        cout << "Ma SV da ton tai!\n";
        return;
    }

    cin.ignore();
    cout << "Ho ten: ";
    getline(cin, sv.hoTen);

    sv.soMon = soMonHoc;
    for (int i = 0; i < soMonHoc; i++) {
        cout << "Diem " << danhSachMon[i] << ": ";
        cin >> sv.diem[i];
    }

    bangBam[sv.maSV] = sv;
}

void tinhDiemTB() {
    for (auto& p : bangBam) {
        float tong = 0;
        for (int i = 0; i < p.second.soMon; i++)
            tong += p.second.diem[i];
        p.second.diemTB = tong / p.second.soMon;
    }
}

void sapXepVaXuatFile(bool giamDan) {
    SinhVien ds[MAX_SV];
    int n = 0;

    for (auto& p : bangBam)
        ds[n++] = p.second;

    // Bubble sort (dễ hiểu)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            bool dieuKien = giamDan ?
                ds[i].diemTB < ds[j].diemTB :
                ds[i].diemTB > ds[j].diemTB;

            if (dieuKien) {
                SinhVien tmp = ds[i];
                ds[i] = ds[j];
                ds[j] = tmp;
            }
        }
    }

    ofstream file("bang_diem.csv");
    file << "MaSV,HoTen";
    for (int i = 0; i < soMonHoc; i++)
        file << "," << danhSachMon[i];
    file << ",DiemTB\n";

    for (int i = 0; i < n; i++) {
        file << ds[i].maSV << "," << ds[i].hoTen;
        for (int j = 0; j < ds[i].soMon; j++)
            file << "," << ds[i].diem[j];
        file << "," << ds[i].diemTB << "\n";
    }

    file.close();
}
