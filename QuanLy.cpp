#include <stdio.h>
#include <string.h>
#include "QuanLy.h"

char danhSachMon[MAX_MON][MAX_LEN];
int soMonHoc = 0;

SinhVien ds[MAX_SV];
int soSV = 0;


void nhapMonHoc() {
    printf("Nhap so mon hoc: ");
    scanf("%d", &soMonHoc);
    getchar();

    for (int i = 0; i < soMonHoc; i++) {
        printf("Ten mon %d: ", i + 1);
        gets(danhSachMon[i]);
    }
}

void themSinhVien() {
    SinhVien sv;

    printf("Ma SV: ");
    gets(sv.maSV);

    for (int i = 0; i < soSV; i++) {
        if (strcmp(ds[i].maSV, sv.maSV) == 0) {
            printf("Ma SV da ton tai!\n");
            return;
        }
    }

    printf("Ho ten: ");
    gets(sv.hoTen);

    sv.soMon = soMonHoc;
    for (int i = 0; i < soMonHoc; i++) {
        printf("Diem %s: ", danhSachMon[i]);
        scanf("%f", &sv.diem[i]);
    }
    getchar();

    sv.diemTB = 0;
    ds[soSV++] = sv;
}

void tinhDiemTB() {
    for (int i = 0; i < soSV; i++) {
        float tong = 0;
        for (int j = 0; j < ds[i].soMon; j++)
            tong += ds[i].diem[j];
        ds[i].diemTB = tong / ds[i].soMon;
    }
}

void sapXepVaXuatFile(int giamDan) {
    for (int i = 0; i < soSV - 1; i++) {
        for (int j = i + 1; j < soSV; j++) {
            int dk = giamDan ?
                ds[i].diemTB < ds[j].diemTB :
                ds[i].diemTB > ds[j].diemTB;

            if (dk) {
                SinhVien t = ds[i];
                ds[i] = ds[j];
                ds[j] = t;
            }
        }
    }

    FILE* f = fopen("bang_diem.csv", "w");
    fprintf(f, "MaSV,HoTen");
    for (int i = 0; i < soMonHoc; i++)
        fprintf(f, ",%s", danhSachMon[i]);
    fprintf(f, ",DiemTB\n");

    for (int i = 0; i < soSV; i++) {
        fprintf(f, "%s,%s", ds[i].maSV, ds[i].hoTen);
        for (int j = 0; j < ds[i].soMon; j++)
            fprintf(f, ",%.2f", ds[i].diem[j]);
        fprintf(f, ",%.2f\n", ds[i].diemTB);
    }
    fclose(f);
}
