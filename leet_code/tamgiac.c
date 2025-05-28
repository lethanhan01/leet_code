#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i < n; i++){
        if(i == 1){
            for(int j = 0; j < n - 1; j++){
                printf(" ");
            }
            printf("$");
            printf("\n");
            continue;
        }
        for(int j = 0; j < n - i; j++){
            printf(" ");
        }
        if(i % 2 == 1){
            printf("$");
            for(int k = 0; k < 2*i - 3; k++){
                printf(" ");
            }
            printf("$");
            printf("\n");
        }else{
            printf("*");
            for(int k = 0; k < 2*i - 3; k++){
                printf(" ");
            }
            printf("*");
            printf("\n");
        }
    }
    if(n % 2 ==1){
        for(int i = 0; i < n; i++){
            printf("$");
            printf(" ");
        }
        printf("\n");
    }else{
        for(int i = 0; i < n; i++){
            printf("*");
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}