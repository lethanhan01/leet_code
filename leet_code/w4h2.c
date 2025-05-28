#include <stdio.h>
#include <string.h>

int dem(char s[]) {
    int m = 0;
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (s[i] == s[j]) {
                m++;
            }
        }
    }
    return m;
}

int main() {
    char s[10000];
    scanf("%s", s);
    printf("%d\n", dem(s));
    return 0;
}
