#include <stdio.h>
#include <math.h>
int cp(int b){
    int c=sqrt(b);
    while(c*c <= b){
    if(c*c == b)
        return 1;
    else
        c +=1;
    }
    return 0;
}
int main(){
    int n,a[1000000];
    scanf("%d", &n);
    for(int i=0; i<n;i++){
        scanf("%d", &a[i]);
    }
    int m=0;
    for(int i=0;i<n;i++){
        if(cp(a[i]) == 1){
            m++;
        }
    }
     printf("%d",m);
    return 0;
}