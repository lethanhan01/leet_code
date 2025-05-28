#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char ch;
    if (argc != 2) {
        printf("Sử dụng: %s <tên_file>\n", argv[0]);
        return 1;
    }
    fp = fopen(argv[1], "r+");
    if (fp == NULL) {
        perror("Lỗi mở file");
        return 1;
    }
    while ((ch = fgetc(fp)) != EOF) {
        if (isalpha(ch)) {
            ch = toupper(ch);
        }
        fseek(fp, -1, SEEK_CUR); 
        fputc(ch, fp);
    }

    fclose(fp);
    return 0;
}