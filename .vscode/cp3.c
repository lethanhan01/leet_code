#include <stdio.h>
int nhapso(){
    int n;
    scanf("%d", &n);
    return n;
}
void chuyen(int n){
    int i;
    while (n != 0)
    {
        printf("%d", n%2);
        n /= 2;
        i++; 
    }
    printf("\n");
}
int main() {
    int n;
    while (n != -1)
    {
        n = nhapso();
        chuyen(n);
    }
    return 0;
}