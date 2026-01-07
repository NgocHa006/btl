#include <iostream>
#include "QuanLy.h"

using namespace std;

int main() {
    int chon;

    nhapMonHoc();

    do {
        cout << "\n===== QUAN LY SINH VIEN =====\n";
        cout << "1. Them sinh vien\n";
        cout << "2. Tinh diem trung binh\n";
        cout << "3. Xuat file (Giam dan)\n";
        cout << "4. Xuat file (Tang dan)\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> chon;

        switch (chon) {
        case 1:
            themSinhVien();
            break;
        case 2:
            tinhDiemTB();
            break;
        case 3:
            sapXepVaXuatFile(true);
            break;
        case 4:
            sapXepVaXuatFile(false);
            break;
        }
    } while (chon != 0);

    return 0;
}
