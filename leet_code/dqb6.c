#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}
int main() {
    int n;
    scanf("%d", &n);
    int a[n], total_weight = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        total_weight += a[i];
    }
    int half_weight = total_weight / 2;
    int dp[half_weight + 1];
    memset(dp, 0, sizeof(dp)); 
    for (int i = 0; i < n; i++) {
        for (int j = half_weight; j >= a[i]; j--) {
            dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
        }
    }
    int closest_sum = dp[half_weight];
    int difference = total_weight - 2 * closest_sum;
    printf("%d\n", abs(difference));
    return 0;
}
