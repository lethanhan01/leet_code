#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
typedef struct _sinhvien {
    char hoten[31];
    float toan;
    float ly;
    float hoa;
} SINHVIEN;

SINHVIEN sv[10];

int main() {
//Nhap
    for (int i = 0; i < 10; i++) {
        scanf("%s", sv[i].hoten);
        printf("sonh vien %d:", i+1);
        scanf("%f", &sv[i].toan);
        scanf("%f", &sv[i].ly);
        scanf("%f", &sv[i].hoa);
    }
//Ghi
    FILE* f = fopen("SV.DAT", "wb");
    if (f == NULL) {
        printf("Khong the mo file.\n");
        return 1;
    }
    for (int i = 0; i < 10; i++) {
        fwrite(&sv[i], sizeof(SINHVIEN), 1, f);
    }
    fclose(f);
    //Doc ra thong tin sv i va in ra man hinh
    int i = 0;
    scanf("%d", &i);
    f = fopen("SV.DAT", "rb");
    if (f == NULL) {
        printf("Khong the mo file.\n");
        return 1;
    }
    fseek(f, i * sizeof(SINHVIEN), SEEK_SET);
    SINHVIEN s;
    fread(&s, sizeof(SINHVIEN), 1, f);
    fclose(f);
    printf("Sinh vien %d: Ho ten: %s, Toan: %.2f, Ly: %.2f, Hoa: %.2f\n", i, s.hoten, s.toan, s.ly, s.hoa);
    //Sua ten sinh vien va ghi lai
    f = fopen("SV.DAT", "rb+");
    if (f == NULL) {
        printf("Khong the mo file.\n");
        return 1;
    }
    fseek(f, i * sizeof(SINHVIEN), SEEK_SET);
    fwrite(&s, sizeof(SINHVIEN), 1, f);
    fclose(f);
    return 0;
}
