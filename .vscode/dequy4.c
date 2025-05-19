#include <stdio.h>
int C(int k,int n){
    if( k==0 || k==n ){
        return 1;
    }
    return C(k-1,n-1)+C(k,n-1);
}
int main(){
    int k,n;
    scanf("%d %d",&k,&n);
    printf("%d", C(k,n));
    return 0;
}