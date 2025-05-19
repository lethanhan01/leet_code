#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    if((a>0) && (b > 0)&&(c>0)){
        if((a+b > c)&&(b+c >a)&&(c+a >b)){
            
            if((a == b )||(b == c)||(c==a)){
                printf("Day la tam giac can");
            }else{
                printf("Day la tam giac khong can");
            }
        }else{
            printf("Day khong phai la tam giac");
        }
    }else{
        printf("Day khong phai la tam giac");
    }
    return 0;
}