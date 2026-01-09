#include <stdio.h>
#include "QuanLy.h"

int main() {
    int chon;
    nhapMonHoc();

    do {
        printf("\n1.Them SV\n2.Tinh DTB\n3.Xuat giam\n4.Xuat tang\n0.Thoat\nChon: ");
        scanf("%d", &chon);
        getchar();

        if (chon == 1) themSinhVien();
        else if (chon == 2) tinhDiemTB();
        else if (chon == 3) sapXepVaXuatFile(1);
        else if (chon == 4) sapXepVaXuatFile(0);

    } while (chon != 0);

    return 0;
}
