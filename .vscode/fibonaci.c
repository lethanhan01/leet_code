#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void fibo(int n){
    long long a[1000000];
    a[0]=1;
    a[1]=1;
    for(int i=2;i<=n;i++){
        a[i]=a[i-1]+a[i-2];
    }
    printf("%lld",a[n-1]);
}
int main() {
    int n;
    scanf("%d",&n);
    fibo(n);
    return 0;
}