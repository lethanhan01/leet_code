#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min_diff = INT_MAX;

void findMinDiff(int a[], int n, int index, int sum1, int sum2) {
    if (index == n) {
        int diff = abs(sum1 - sum2);
        if (diff < min_diff) {
            min_diff = diff;
        }
        return;
    }
    findMinDiff(a, n, index + 1, sum1 + a[index], sum2);
    findMinDiff(a, n, index + 1, sum1, sum2 + a[index]);
}
int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    findMinDiff(a, n, 0, 0, 0);
    printf("%d\n", min_diff);
    return 0;
}
