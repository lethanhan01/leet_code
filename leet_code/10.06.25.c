#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_SCHOOL 50

typedef struct {
    char hoTen[MAX_NAME];
    char soBaoDanh[20];
    char truong[MAX_SCHOOL];
    float diemThi;
} ThiSinh;

void nhapThiSinh(ThiSinh *ts) {
    printf("\nNhap ho ten thi sinh (*** de ket thuc): ");
    fflush(stdin);
    fgets(ts->hoTen, MAX_NAME, stdin);
    ts->hoTen[strcspn(ts->hoTen, "\n")] = 0;
    
    if (strcmp(ts->hoTen, "***") == 0) return;
    
    printf("Nhap so bao danh: ");
    fgets(ts->soBaoDanh, 20, stdin);
    ts->soBaoDanh[strcspn(ts->soBaoDanh, "\n")] = 0;
    
    printf("Nhap truong du thi: ");
    fgets(ts->truong, MAX_SCHOOL, stdin);
    ts->truong[strcspn(ts->truong, "\n")] = 0;
    
    printf("\nNhap diem thi: ");
    scanf("%f", &ts->diemThi);
    while(getchar() != '\n'); 
}

void ghiFile(ThiSinh ts) {
    FILE *f = fopen("ThiSinh.dat", "ab");
    if (f == NULL) {
        printf("Khong the mo file!\n");
        return;
    }
    fwrite(&ts, sizeof(ThiSinh), 1, f);
    fclose(f);
}

void docVaHienThiBKHN() {
    FILE *f = fopen("ThiSinh.dat", "rb");
    if (f == NULL) {
        printf("Khong the mo file!\n");
        return;
    }
    
    printf("\nDanh sach thi sinh BKHN co diem > 20:\n");
    printf("STT\tSoBaoDanh\tHoTen\t\tDiemThi\n");
    
    ThiSinh ts;
    int stt = 1;
    
    while (fread(&ts, sizeof(ThiSinh), 1, f) == 1) {
        if (strstr(ts.truong, "hust") != NULL && ts.diemThi > 20) {
            printf("%d\t%s\t\t%s\t%.2f\n", stt++, ts.soBaoDanh, ts.hoTen, ts.diemThi);
        }
    }
    fclose(f);
}

void taoFileBKHN() {
    FILE *f1 = fopen("ThiSinh.dat", "rb");
    FILE *f2 = fopen("BKHN.dat", "wb");
    
    if (f1 == NULL || f2 == NULL) {
        printf("Khong the mo file!\n");
        return;
    }
    
    ThiSinh ts;
    while (fread(&ts, sizeof(ThiSinh), 1, f1) == 1) {
        if (strstr(ts.truong, "hust") != NULL) {
            fwrite(&ts, sizeof(ThiSinh), 1, f2);
        }
    }
    
    fclose(f1);
    fclose(f2);
    printf("\nDa tao file BKHN.dat thanh cong!\n");
}

void timThiSinh() {
    char sbd[20];
    printf("\nNhap so bao danh can tim: ");
    fflush(stdin);
    fgets(sbd, 20, stdin);
    sbd[strcspn(sbd, "\n")] = 0;
    
    FILE *f = fopen("ThiSinh.dat", "rb");
    if (f == NULL) {
        printf("Khong the mo file!\n");
        return;
    }
    
    ThiSinh ts;
    int timThay = 0;
    
    while (fread(&ts, sizeof(ThiSinh), 1, f) == 1) {
        if (strcmp(ts.soBaoDanh, sbd) == 0) {
            printf("\nho ten: %s\n", ts.hoTen);
            printf("so bao danh: %s\n", ts.soBaoDanh);
            printf("truong du thi: %s\n", ts.truong);
            printf("diem thi: %.2f\n", ts.diemThi);
            timThay = 1;
            break;
        }
    }
    
    if (!timThay) {
        printf("khong tim thay\n");
    }
    
    fclose(f);
}

int main() {
    ThiSinh ts;
    
    // Nhap danh sach thi sinh
    while (1) {
        nhapThiSinh(&ts);
        if (strcmp(ts.hoTen, "***") == 0) break;
        ghiFile(ts);
    }
    
    // Doc va hien thi thi sinh BKHN
    docVaHienThiBKHN();
    
    // Tao file BKHN
    taoFileBKHN();
    
    // Tim thi sinh theo so bao danh
    timThiSinh();
    
    return 0;
}
