#pragma once
#include <string>

#define MAX_MON 10

struct SinhVien {
    std::string maSV;
    std::string hoTen;
    float diem[MAX_MON];
    int soMon = 0;
    float diemTB = 0;
};
