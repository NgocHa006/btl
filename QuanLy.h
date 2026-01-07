#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include "SinhVien.h"

// Danh sách môn học
extern std::vector<std::string> danhSachMon;

// Bảng băm sinh viên
extern std::unordered_map<std::string, SinhVien> bangBam;

// Các hàm xử lý
void nhapMonHoc();
void themSinhVien();
void tinhDiemTB();
void sapXepVaXuatFile(bool giamDan);
