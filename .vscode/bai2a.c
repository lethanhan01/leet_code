#include <stdio.h>
#include <ctype.h>

int main() {
    char s[100];
    int count[26] = {0};
    fgets(s, 100, stdin);

    for (int i = 0; s[i] != '\0'; i++) {
        if (isalpha(s[i]) && islower(s[i])) {
            count[s[i] - 'a']++;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            printf("The letter '%c' appears %d time(s).\n", 'a' + i, count[i]);
        }
    }

    return 0;
}