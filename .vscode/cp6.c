#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int a[1000];
    for(int i =0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int s =0;
    for(int i =0; i< n; i++){
        s+= a[i];
    }

    printf("%d\n", s);
    for(int i = 0; i < n; i++){
        if(a[i] %3 ==0 && a[i] > 10){
            printf("%d\n", a[i]);
        }
    }
    for(int i = 0; i< n; i++){
        if(a[i] >= 100 && a[i] <= 1000){
            printf("%d\n", a[i]);
        }
    }
    return 0;
}