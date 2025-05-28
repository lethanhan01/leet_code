#include <stdio.h>

void np(int K, char *s, int n) {
    if (n == K) {
        printf("%s\n", s);
        return;
    }
    s[n] = '0'; 
    s[n + 1] = '\0';
    np(K, s, n + 1);
    if (n == 0 || s[n - 1] != '1') { 
        s[n] = '1';
        np(K, s, n + 1);
    }
}

int main() {
    int K;
    scanf("%d", &K);
    char s[K + 1]; 
    np(K, s, 0);
    return 0;
}
