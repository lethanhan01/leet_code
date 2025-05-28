#include <stdio.h>
int nhiphan(int n){
    if(n==0){
        return 0;
    }
    int b=n%2;
    nhiphan(n/2);
    printf("%d", b);    
}
int main(){
    int n;
    scanf("%d", &n);
    nhiphan(n);
    return 0;
}