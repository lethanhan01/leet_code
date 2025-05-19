#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Khai báo kiểu chuỗi ký tự có độ dài tối đa 101
typedef char STRING[101];

// Khai báo cấu trúc để lưu thông tin thí sinh
typedef struct {
    STRING code;
    int score;
} student;

// Khai báo biến toàn cục
int n = 0;
student an[1000]; // Giả sử tối đa có 1000 thí sinh

// Hàm nhập dữ liệu
void input() {
    int m = 0;
    while (1) {
        char input[50];
        fgets(input, sizeof(input), stdin);
        if (input[0] == '#') break;
        sscanf(input, "%s %d", an[m].code, &an[m].score);
        m++;
        n++;
    }
}

// Hàm merge để hợp nhất hai mảng đã được sắp xếp
void merge(int b[], int L, int R, int M) {
    int t[100005]; // Mảng tạm thời để lưu kết quả hợp nhất
    int k = L;
    int i = L;
    int j = M + 1;
    while (k <= R) {
        if (i > M) {
            t[k] = b[j];
            j++;
        } else if (j > R) {
            t[k] = b[i];
            i++;
        } else {
            if (b[i] <= b[j]) {
                t[k] = b[i];
                i++;
            } else {
                t[k] = b[j];
                j++;
            }
        }
        k++;
    }
    memcpy(b + L, t + L, (R - L + 1) * sizeof(int));
}

// Hàm mergesort để sắp xếp mảng theo phương pháp merge sort
void mergesort(int b[], int L, int R) {
    if (L < R) {
        int M = (L + R) / 2;
        mergesort(b, L, M);
        mergesort(b, M + 1, R);
        merge(b, L, R, M);
    }
}

// Hàm sapxep3 để sắp xếp lại các mã thí sinh theo điểm số đã sắp xếp
void sapxep3(int b[], int e[], STRING a[], STRING c[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (b[i] == e[j]) {
                strcpy(c[j], a[i]);
            }
        }
    }
}

int main() {
    // Nhập dữ liệu
    input();

    // Sao chép mã thí sinh và điểm số vào các mảng tạm thời
    STRING c[1000];
    int d[1000];
    for (int i = 0; i < n; i++) {
        strcpy(c[i], an[i].code);
        d[i] = an[i].score;
    }

    // Sắp xếp điểm số theo thứ tự tăng dần
    int scores[1000];
    for (int i = 0; i < n; i++) {
        scores[i] = an[i].score;
    }
    mergesort(scores, 0, n - 1);

    // Sắp xếp lại các mã thí sinh theo điểm số đã sắp xếp
    sapxep3(d, scores, c, an->code, n);

    // In kết quả
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", c[i], scores[i]);
    }

    return 0;
}
