#include <stdio.h>
int main(){
    int n,a[100000],s=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
        s += a[i];
    }
    printf("%d", s);
    return 0;
}