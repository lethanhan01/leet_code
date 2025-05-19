#include <stdio.h>
int fibonacci(int n){
    int m;
        if(m<=1){
          return n;  
        }
        return (fibonacci(n-1)+fibonacci(n-2))%100000000;
        
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",fibonacci(n));
    return 0;
}