#include <stdio.h>
#include <math.h>
int main(){
    int n;
    scanf("%d",&n);
    int i;
    for(i=n;i>0;i--){
        if(n%i==0){
            printf("-%d ",i);
        }
    }
    for(int i=1;i<=n;i++){
         if(n%i==0){
            printf("%d ",i);
        }
    }
    return 0;
}