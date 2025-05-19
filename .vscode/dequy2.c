#include <stdio.h>
int n;
int A,B,C;
void chuyen(int n,int A,int B,int C){
    if(n==1){
        printf("%d -> %d \n",A,B);
        return;
    }
    chuyen(n-1,A,C,B);
    chuyen(1,A,B,C);
    chuyen(n-1,C,B,A);
}
int main(){
    scanf("%d %d %d %d",&n,&A,&B,&C);
    int m=1;
    for(int i=0;i<=n;i++){
        m*=2;
        m=m-1;
    }
    printf("%d\n",m);
    chuyen(n,A,B,C);
    return 0;
}