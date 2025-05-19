#include <stdio.h>
int fb(int n){
    if(n==1) return 1;
    else if(n==2) return 1;
    else return fb(n-1)+fb(n-2);
}
int main() {
    int n;
    scanf("%d",&n);
    printf("%d",fb(n));
    return 0;
}