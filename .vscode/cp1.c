#include <stdio.h>
int nhapso(){
    int n;
    scanf("%d", &n);
    return n;
}
int max(int a, int b){
    return a > b ? a : b;
}
int main() {
    int a = nhapso();
    int b = nhapso();
    int c = nhapso();
    printf("%d\n", max(c,max(a, b)));
    return 0;
}