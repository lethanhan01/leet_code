#include <stdio.h>
#include <string.h>
int count = 0;
void ktra(char *str, int n, int index) {
    if (index == n) {
        int leftSum = 0, rightSum = 0, mid = n / 2;
        for (int i = 0; i < mid; i++) {
            leftSum += str[i] - '0';
        }
        for (int i = (n % 2 == 0 ? mid : mid + 1); i < n; i++) {
            rightSum += str[i] - '0';
        }
        if (leftSum == rightSum) {
            count++;
        }
        return;
    }
    str[index] = '0';
    ktra(str, n, index + 1);
    str[index] = '1';
    ktra(str, n, index + 1);
}
int main() {
    int n;
    scanf("%d", &n);
    char str[n + 1];
    memset(str, 0, sizeof(str));
    ktra(str, n, 0);
    printf("%d\n", count);
    return 0;
}
