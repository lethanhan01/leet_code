#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STUDENTS 1000
#define MAX_NAME_LENGTH 100

// Cấu trúc thí sinh
typedef struct {
    char hoTen[MAX_NAME_LENGTH];
    float diemToan;
    float diemLy;
    float diemHoa;
    float tongDiem;
} ThiSinh;

int nhapDanhSach(ThiSinh ds[]) {
    int n = 0;
    printf("Nhap danh sach thi sinh (nhap ten rong de ket thuc):\n");
    
    while (n < MAX_STUDENTS) {
        printf("\n--- Thi sinh thu %d ---\n", n + 1);
        printf("Ho ten: ");
        fflush(stdin);
        fgets(ds[n].hoTen, MAX_NAME_LENGTH, stdin);
        ds[n].hoTen[strcspn(ds[n].hoTen, "\n")] = 0;
        
        if (strlen(ds[n].hoTen) == 0) {
            break;
        }
        printf("Diem Toan: ");
        scanf("%f", &ds[n].diemToan);
        printf("Diem Ly: ");
        scanf("%f", &ds[n].diemLy);
        printf("Diem Hoa: ");
        scanf("%f", &ds[n].diemHoa);        
        ds[n].tongDiem = ds[n].diemToan + ds[n].diemLy + ds[n].diemHoa;
        n++;
    }
    
    return n;
}

void inThiSinh(ThiSinh ts) {
    printf("%-25s %6.2f %6.2f %6.2f %8.2f\n", 
           ts.hoTen, ts.diemToan, ts.diemLy, ts.diemHoa, ts.tongDiem);
}
void sapxep(ThiSinh ds[], int n){
    // Bubble Sort - sắp xếp theo tổng điểm từ cao đến thấp
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // So sánh hai phần tử liền kề
            if (ds[j].tongDiem < ds[j + 1].tongDiem) {
                // Hoán đổi nếu phần tử trước nhỏ hơn phần tử sau
                ThiSinh temp = ds[j];
                ds[j] = ds[j + 1];
                ds[j + 1] = temp;
            }
        }
    }
}
void inDanhSachTrungTuyen(ThiSinh ds[], int n, float diemChuan) {
    printf("\n=== DANH SACH THI SINH TRUNG TUYEN (Diem chuan: %.2f) ===\n", diemChuan);
    printf("%-25s %6s %6s %6s %8s\n", "Ho Ten", "Toan", "Ly", "Hoa", "Tong");
    printf("----------------------------------------------------------------\n");
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (ds[i].tongDiem >= diemChuan) {
            inThiSinh(ds[i]);
            count++;
        }
    }
    
    if (count == 0) {
        printf("Khong co thi sinh nao trung tuyen!\n");
    } else {
        printf("Tong so thi sinh trung tuyen: %d\n", count);
    }
}

void timThiSinhDiemCaoNhat(ThiSinh ds[], int n) {
    if (n == 0) return;
    
    float maxDiem = ds[0].tongDiem;
    for (int i = 1; i < n; i++) {
        if (ds[i].tongDiem > maxDiem) {
            maxDiem = ds[i].tongDiem;
        }
    }
    
    printf("\n=== THI SINH CO DIEM CAO NHAT (%.2f diem) ===\n", maxDiem);
    printf("%-25s %6s %6s %6s %8s\n", "Ho Ten", "Toan", "Ly", "Hoa", "Tong");
    printf("----------------------------------------------------------------\n");
    
    for (int i = 0; i < n; i++) {
        if (ds[i].tongDiem == maxDiem) {
            inThiSinh(ds[i]);
        }
    }
}

// Hàm so sánh để sắp xếp theo tổng điểm giảm dần
int compare(const void *a, const void *b) {
    ThiSinh *tsA = (ThiSinh *)a;
    ThiSinh *tsB = (ThiSinh *)b;
    
    if (tsB->tongDiem > tsA->tongDiem) return 1;
    if (tsB->tongDiem < tsA->tongDiem) return -1;
    return 0;
}

// Hàm tìm điểm chuẩn theo số lượng tối đa
float timDiemChuan(ThiSinh ds[], int n, int soLuongToiDa) {
    if (n == 0 || soLuongToiDa <= 0) return 0;
    
    // Tạo bản sao và sắp xếp theo điểm giảm dần
    ThiSinh *temp = (ThiSinh *)malloc(n * sizeof(ThiSinh));
    for (int i = 0; i < n; i++) {
        temp[i] = ds[i];
    }
    
    qsort(temp, n, sizeof(ThiSinh), compare);
    
    // In bảng xếp hạng
    printf("\n=== BANG XEP HANG ===\n");
    printf("%-4s %-25s %8s\n", "STT", "Ho Ten", "Tong Diem");
    printf("----------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-4d %-25s %8.2f\n", i+1, temp[i].hoTen, temp[i].tongDiem);
    }
    
    float diemChuan = 0;
    
    if (soLuongToiDa >= n) {
        // Nếu số lượng tối đa >= tổng số thí sinh
        diemChuan = temp[n-1].tongDiem;
    } else {
        // Tìm điểm của thí sinh thứ soLuongToiDa
        float diemThuK = temp[soLuongToiDa - 1].tongDiem;
        
        // Kiểm tra xem có thí sinh nào ở vị trí soLuongToiDa+1 trở đi có cùng điểm không
        bool coDiemTrung = false;
        for (int i = soLuongToiDa; i < n; i++) {
            if (temp[i].tongDiem == diemThuK) {
                coDiemTrung = true;
                break;
            }
        }
        
        if (coDiemTrung) {
            // Nếu có điểm trùng, loại tất cả thí sinh có điểm bằng điểm thứ K
            // Tìm điểm cao hơn điểm thứ K
            diemChuan = -1; // Đánh dấu không tìm được điểm chuẩn phù hợp
            for (int i = 0; i < soLuongToiDa - 1; i++) {
                if (temp[i].tongDiem > diemThuK) {
                    diemChuan = diemThuK + 0.01f; // Đặt điểm chuẩn cao hơn một chút
                    break;
                }
            }
            
            if (diemChuan == -1) {
                printf("\nKhong the xac dinh diem chuan vi co nhieu thi sinh cung diem!\n");
                printf("Goi y: Tang so luong toi da hoac xem xet lai yeu cau.\n");
                free(temp);
                return 0;
            }
        } else {
            diemChuan = diemThuK;
        }
    }
    
    free(temp);
    return diemChuan;
}

int main() {
    ThiSinh danhSach[MAX_STUDENTS];
    int soLuongThiSinh;
    float diemChuan;
    int luaChon;
    
    printf("=== CHUONG TRINH QUAN LY THI SINH ===\n\n");
    
    soLuongThiSinh = nhapDanhSach(danhSach);
    printf("\nDa nhap %d thi sinh.\n", soLuongThiSinh);
    
    if (soLuongThiSinh == 0) {
        printf("Khong co thi sinh nao. Ket thuc chuong trinh.\n");
        return 0;
    }
    
    do {
        printf("\n=== MENU ===\n");
        printf("1. Xem danh sach thi sinh trung tuyen (nhap diem chuan)\n");
        printf("2. Tim thi sinh co diem cao nhat\n");
        printf("3. Tim diem chuan theo so luong toi da\n");
        printf("4. In toan bo danh sach\n");
        printf("5. Sap xep danh sach theo diem (Bubble Sort)\n");
        printf("0. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &luaChon);
        
        switch (luaChon) {
            case 1:
                printf("Nhap diem chuan: ");
                scanf("%f", &diemChuan);
                inDanhSachTrungTuyen(danhSach, soLuongThiSinh, diemChuan);
                break;
                
            case 2:
                timThiSinhDiemCaoNhat(danhSach, soLuongThiSinh);
                break;
                
            case 3: {
                int K;
                printf("Nhap so luong toi da: ");
                scanf("%d", &K);
                diemChuan = timDiemChuan(danhSach, soLuongThiSinh, K);
                if (diemChuan > 0) {
                    printf("\nDiem chuan tim duoc: %.2f\n", diemChuan);
                    inDanhSachTrungTuyen(danhSach, soLuongThiSinh, diemChuan);
                }
                break;
            }
            
            case 4:
                printf("\n=== TOAN BO DANH SACH THI SINH ===\n");
                printf("%-25s %6s %6s %6s %8s\n", "Ho Ten", "Toan", "Ly", "Hoa", "Tong");
                printf("----------------------------------------------------------------\n");
                for (int i = 0; i < soLuongThiSinh; i++) {
                    inThiSinh(danhSach[i]);
                }
                break;
                
            case 5:
                printf("\n=== SAP XEP DANH SACH THEO DIEM (BUBBLE SORT) ===\n");
                printf("Danh sach truoc khi sap xep:\n");
                printf("%-25s %6s %6s %6s %8s\n", "Ho Ten", "Toan", "Ly", "Hoa", "Tong");
                printf("----------------------------------------------------------------\n");
                for (int i = 0; i < soLuongThiSinh; i++) {
                    inThiSinh(danhSach[i]);
                }
                
                sapxep(danhSach, soLuongThiSinh);
                
                printf("\nDanh sach sau khi sap xep (cao -> thap):\n");
                printf("%-25s %6s %6s %6s %8s\n", "Ho Ten", "Toan", "Ly", "Hoa", "Tong");
                printf("----------------------------------------------------------------\n");
                for (int i = 0; i < soLuongThiSinh; i++) {
                    inThiSinh(danhSach[i]);
                }
                break;
                
            case 0:
                printf("Ket thuc chuong trinh. Cam on ban!\n");
                break;
                
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (luaChon != 0);
    
    return 0;
}
