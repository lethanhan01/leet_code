#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(){
    double a, b,c;
    scanf("%lf %lf %lf", &a, &b, &c);
    if(a == b && b == c){
        printf("Tam giac deu");
    }else if(a == b || b == c || a == c){
        printf("Tam giac can"); 
    }else if(a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a){
        printf("Tam giac vuong");
    }else{
        printf("Tam giac thuong");
    }
}