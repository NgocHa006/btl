#pragma once

#define MAX_SV 1000   
#define MAX_MON 10
#define MAX_LEN 50

struct SinhVien {
    char maSV[MAX_LEN];
    char hoTen[MAX_LEN];
    float diem[MAX_MON];
    int soMon;
    float diemTB;
};
