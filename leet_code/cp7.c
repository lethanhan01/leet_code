#include <stdio.h>


void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


void bubble_sort(int* m, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) { 
            if (m[j] > m[j + 1]) {
                swap(&m[j], &m[j + 1]);
                
                
                printf("After swapping %d and %d: ", m[j], m[j + 1]);
                for (int k = 0; k < n; k++) {
                    printf("%d ", m[k]);
                }
                printf("\n");
            }
        }
    }
}

int main() {
    int n;

    // Nhập số phần tử của mảng
    printf("Enter the number of elements (1-100): ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 100) {
        printf("Error: Invalid input. Please enter a number between 1 and 100.\n");
        return 1;
    }

    int m[100];

    // Nhập các phần tử của mảng
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &m[i]) != 1) {
            printf("Error: Invalid input for array elements.\n");
            return 1;
        }
    }

    // In mảng ban đầu
    printf("Initial array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", m[i]);
    }
    printf("\n");

    // Gọi hàm sắp xếp
    bubble_sort(m, n);

    // In mảng sau khi sắp xếp
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", m[i]);
    }
    printf("\n");

    return 0;
}