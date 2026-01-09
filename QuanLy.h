#pragma once
#include "SinhVien.h"

extern char danhSachMon[MAX_MON][MAX_LEN];
extern int soMonHoc;

extern SinhVien ds[MAX_SV];
extern int soSV;

void nhapMonHoc();
void themSinhVien();
void tinhDiemTB();
void sapXepVaXuatFile(int giamDan);
