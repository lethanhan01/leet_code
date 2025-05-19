#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cấu trúc dữ liệu để lưu thông tin thí sinh
typedef struct {
    char code[11]; // Mã thí sinh có độ dài từ 2 đến 10 ký tự
    int score;     // Điểm số (số nguyên từ 0 đến 1000000)
} Student;

// Hàm để hợp nhất hai mảng đã được sắp xếp
void merge(Student arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Tạo các mảng tạm thời
    Student *L = (Student*)malloc(n1 * sizeof(Student));
    Student *R = (Student*)malloc(n2 * sizeof(Student));
    
    // Sao chép dữ liệu vào các mảng tạm thời
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    // Hợp nhất các mảng tạm thời lại thành mảng đã sắp xếp
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].score >= R[j].score) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Sao chép các phần tử còn lại của L[], nếu có
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Sao chép các phần tử còn lại của R[], nếu có
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    free(L);
    free(R);
}

// Hàm sắp xếp merge sort
void mergeSort(Student arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        // Sắp xếp nửa đầu và nửa sau
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        // Hợp nhất hai nửa đã sắp xếp
        merge(arr, left, mid, right);
    }
}

int main() {
    Student students[100]; // Giả sử tối đa có 100 thí sinh
    int count = 0;
    
    // Nhập dữ liệu từ người dùng
    while (1) {
        char input[50];
        fgets(input, sizeof(input), stdin);
        
        if (input[0] == '#') break;
        
        sscanf(input, "%s %d", students[count].code, &students[count].score);
        count++;
    }
    
    // Sắp xếp các thí sinh theo điểm số giảm dần
    mergeSort(students, 0, count - 1);
    
    // In kết quả
    for (int i = 0; i < count; i++) {
        printf("%s %d\n", students[i].code, students[i].score);
    }
    
    return 0;
}
