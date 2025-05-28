#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        return 1;
    }
    for (int i = argc - 1; i > 0; i--) {
        printf("%s", argv[i]);
        if (i > 1) {
            printf(" ");
        }
    }
    printf("\n"); 

    return 0;
}
