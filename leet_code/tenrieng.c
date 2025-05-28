#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100005
#define NAME_LEN 101

char names[MAX][NAME_LEN];
char firstNames[MAX][NAME_LEN];

int main() {
    int n;

    // Đọc số lượng học sinh
    scanf("%d", &n);

    // Đọc tên đầy đủ của từng học sinh
    for (int i = 0; i < n; i++) {
        scanf(" %[^\n]", names[i]);
    }

    // Trích xuất tên từ tên đầy đủ
    for (int i = 0; i < n; i++) {
        char *token = strtok(names[i], " ");
        char *lastToken;
        while (token != NULL) {
            lastToken = token;
            token = strtok(NULL, " ");
        }
        strcpy(firstNames[i], lastToken);
    }

    // In ra các tên đã được trích xuất
    for (int i = 0; i < n; i++) {
        printf("%s\n", firstNames[i]);
    }

    return 0;
}
