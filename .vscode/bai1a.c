#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define constant 8
int main(){
    double a[100000],s;
    for(int i=0;i<8;i++){
        scanf("%lf", &a[i]);
        s += a[i];    
    }
    double average = s/8;
    printf("Trung binh: %.2lf\n", average);
    double h[1000];
    for(int i=0;i<8;i++){
        h[i]=average-a[i];
    }
    double m[1000];
    for(int i=0;i<8;i++){
        m[i]=abs(average-a[i]);
    }
    double min = m[0];
    for(int i=0;i<8;i++){
        if(m[i] < min){
            min = m[i];
        }
    }
    for(int i=0;i<8;i++){
        if(m[i] == min){
        printf("%d %.2lf",i,a[i]);
        }
    }
    return 0;
}