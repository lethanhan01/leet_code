#include <stdio.h>
int songuyento(int a){
    int i, dem = 0;
    for (i = 1; i <= a; i++) {
        if (a % i == 0) {
            dem++;
        }
    }
    if (dem == 2) {
        return 1;  
    } else {
        return 0; 
    }
}
void nhap(){
    while(1){
        int a;
        scanf("%d", &a);
        if (a > 0) {
            if (songuyento(a) == 1) {
                printf("1\n");
            } else {
                printf("0\n");
            }
            nhap();
        } else {
            break;
        }
    }
}
int tongchuso(int a){
    int i, dem = 0;
    while (a > 0) {
        dem += a % 10;
        a /= 10;
    }
    return dem;
}
int tongcacuoc(int a){
    int i, dem = 0;
    for (i = 1; i <= a; i++) {
        if (a % i == 0) {
            dem++;
        }
    }
    return dem;
}
int main() {
    nhap();
    return 0;
}