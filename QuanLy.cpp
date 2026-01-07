#include "QuanLy.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

// Định nghĩa biến toàn cục
vector<string> danhSachMon;
unordered_map<string, SinhVien> bangBam;

// Nhập danh sách môn học
void nhapMonHoc() {
    int n;
    cout << "Nhap so mon hoc: ";
    cin >> n;
    cin.ignore();

    danhSachMon.clear();
    for (int i = 0; i < n; i++) {
        string ten;
        cout << "Ten mon " << i + 1 << ": ";
        getline(cin, ten);
        danhSachMon.push_back(ten);
    }
}

// Thêm sinh viên (HASH TABLE)
void themSinhVien() {
    SinhVien sv;
    cout << "Ma SV: ";
    cin >> sv.maSV;

    if (bangBam.find(sv.maSV) != bangBam.end()) {
        cout << "Ma SV da ton tai!\n";
        return;
    }

    cin.ignore();
    cout << "Ho ten: ";
    getline(cin, sv.hoTen);

    sv.diem.resize(danhSachMon.size());
    for (int i = 0; i < danhSachMon.size(); i++) {
        cout << "Diem " << danhSachMon[i] << ": ";
        cin >> sv.diem[i];
    }

    bangBam[sv.maSV] = sv;
}

// Tính điểm trung bình
void tinhDiemTB() {
    for (auto& p : bangBam) {
        float tong = 0;
        for (float d : p.second.diem)
            tong += d;
        p.second.diemTB = tong / p.second.diem.size();
    }
}

// Sắp xếp + xuất file
void sapXepVaXuatFile(bool giamDan) {
    vector<SinhVien> v;
    for (auto& p : bangBam)
        v.push_back(p.second);

    sort(v.begin(), v.end(), [giamDan](SinhVien a, SinhVien b) {
        return giamDan ? a.diemTB > b.diemTB : a.diemTB < b.diemTB;
        });

    ofstream file("bang_diem.csv");
    file << "MaSV,HoTen";
    for (auto& m : danhSachMon)
        file << "," << m;
    file << ",DiemTB\n";

    for (auto& sv : v) {
        file << sv.maSV << "," << sv.hoTen;
        for (float d : sv.diem)
            file << "," << d;
        file << "," << sv.diemTB << "\n";
    }

    file.close();
}
