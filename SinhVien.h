#pragma once
#include <string>
#include <vector>

struct SinhVien {
    std::string maSV;
    std::string hoTen;
    std::vector<float> diem;
    float diemTB = 0;
};
