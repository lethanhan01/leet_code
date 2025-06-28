
#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char hoTen[31];
    float toan;
    float ly;
    float hoa;
    float tong;
} ThiSinh;

void nhapDanhSach(ThiSinh ds[], int *n) {
    *n = 0;
    while (1) {
        fgets(ds[*n].hoTen, 31, stdin);
        ds[*n].hoTen[strcspn(ds[*n].hoTen, "\n")] = '\0'; 

        if (strlen(ds[*n].hoTen) == 0)
            break;

        printf("Nhap diem Toan: ");
        scanf("%f", &ds[*n].toan);
        printf("Nhap diem Ly: ");
        scanf("%f", &ds[*n].ly);
        printf("Nhap diem Hoa: ");
        scanf("%f", &ds[*n].hoa);

        ds[*n].tong = ds[*n].toan + ds[*n].ly + ds[*n].hoa;
        (*n)++;
        getchar(); 
    }
}

void inThiSinhTrungTuyen(ThiSinh ds[], int n, float diemChuan) {
    printf("\nDanh sach trung tuyen:\n", diemChuan);
    for (int i = 0; i < n; i++) {
        if (ds[i].tong >= diemChuan) {
            printf("%s (%.2f)\n", ds[i].hoTen, ds[i].tong);
        }
    }
}

void inThiSinhCaoNhat(ThiSinh ds[], int n) {
    if (n == 0) return;
    float max = ds[0].tong;
    for (int i = 1; i < n; i++) {
        if (ds[i].tong > max)
            max = ds[i].tong;
    }
    printf("\nThi sinh tong diem cao nhat:\n");
    for (int i = 0; i < n; i++) {
        if (ds[i].tong == max) {
            printf("%s (%.2f)\n", ds[i].hoTen, ds[i].tong);
        }
    }
}

void timDiemChuan(ThiSinh ds[], int n, int K) {
    ThiSinh temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (ds[i].tong < ds[j].tong) {
                temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }

    float diemChuanHopLe = -1;
    for (int i = n-1; i >0; i--) {
        float diemChuan = ds[i].tong;
        int countTren = 0, countBang = 0;

        for (int j = 0; j < n; j++) {
            if (ds[j].tong > diemChuan) countTren++;
            else if (ds[j].tong == diemChuan) countBang++;
        }

        if (countTren < K && countTren + countBang <= K) {
            diemChuanHopLe = diemChuan;
            break;
        }
    }

    if (diemChuanHopLe == -1) {
        printf("\nKhong co.\n");
    } else {
        printf("\nDiem chuan: %.2f\n", diemChuanHopLe);
        printf("Danh sach trung tuyen:\n");
        for (int j = 0; j < n; j++) {
            if (ds[j].tong >= diemChuanHopLe) {
                printf("%s (%.2f)\n", ds[j].hoTen, ds[j].tong);
            }
        }
    }
}


int main() {
    ThiSinh ds[MAX];
    int n;
    nhapDanhSach(ds, &n);

    float diemChuan;
    printf("\nNhap diem chuan: ");
    scanf("%f", &diemChuan);
    inThiSinhTrungTuyen(ds, n, diemChuan);

    inThiSinhCaoNhat(ds, n);

    int k;
    printf("\nNhap so luong thi sinh toi da: ");
    scanf("%d", &k);
    timDiemChuan(ds, n, k);

    return 0;
}