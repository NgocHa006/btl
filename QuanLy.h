#pragma once
#include <string>
#include <unordered_map>
#include "SinhVien.h"

#define MAX_SV 100

extern std::string danhSachMon[MAX_MON];
extern int soMonHoc;

extern std::unordered_map<std::string, SinhVien> bangBam;

void nhapMonHoc();
void themSinhVien();
void tinhDiemTB();
void sapXepVaXuatFile(bool giamDan);
