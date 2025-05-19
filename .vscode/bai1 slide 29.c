#include <stdio.h>
#include <stdlib.h>

void displayFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
}

void displayFilePaged(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char ch;
    int lineCount = 0;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
        if (ch == '\n') {
            lineCount++;
        }
        if (lineCount == 25) { // Giả sử mỗi trang có 25 dòng
            printf("\nPress any key to continue...\n");
            getchar();
            lineCount = 0;
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename> [-p]\n", argv[0]);
        return 1;
    }

    if (argc == 3 && strcmp(argv[2], "-p") == 0) {
        displayFilePaged(argv[1]);
    } else {
        displayFile(argv[1]);
    }

    return 0;
}
