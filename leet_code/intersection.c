#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

int n = 0;
int m = 2;
int a[1000005][10] = {0};
int t[1000005][10] = {0};

void merge(int a[][10], int L, int R, int M) {
    int k = L;
    int i = L;
    int j = M + 1;
    while (k <= R) {
        int compare = 0;
        for (int l = 0; l < m; l++) {
            if (a[i][l] < a[j][l]) {
                compare = -1;
                break;
            } else if (a[i][l] > a[j][l]) {
                compare = 1;
                break;
            }
        }
        if (i > M) {
            for (int l = 0; l < m; l++) {
                t[k][l] = a[j][l];
            }
            j++;
        } else if (j > R) {
            for (int l = 0; l < m; l++) {
                t[k][l] = a[i][l];
            }
            i++;
        } else if (compare <= 0) {
            for (int l = 0; l < m; l++) {
                t[k][l] = a[i][l];
            }
            i++;
        } else {
            for (int l = 0; l < m; l++) {
                t[k][l] = a[j][l];
            }
            j++;
        }
        k++;
    }
    for (k = L; k <= R; k++) {
        for (int l = 0; l < m; l++) {
            a[k][l] = t[k][l];
        }
    }
}

void mergesort(int a[][10], int L, int R) {
    if (L < R) {
        int M = (L + R) / 2;
        mergesort(a, L, M);
        mergesort(a, M + 1, R);
        merge(a, L, R, M);
    }
}
int sapxep(int a[][10], int n) {
    for (int i = 0; i < n; i++) {
        if(a[i][1] > a[i+1][0]) {
            return 1;
        }
        else {
            return 0;
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    mergesort(a, 0, n - 1);

    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }*/
    if(sapxep(a,n) == 1) {
        printf("TRUE");
    }
    else {
        printf("FALSE");
    }
    return 0;
}
