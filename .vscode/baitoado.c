#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
typedef struct{
    double x, y;
}Point;
typedef struct{
    double x1, y1, x2, y2;
}Rect;
int n,m;
Point cars[100005];
Rect rect[100005];
int count = 0;
void input(){
    scanf("%d %d", &n, &m);   
    for(int i = 0; i < n; i++){
        scanf("%lf %lf", &cars[i].x, &cars[i].y);
    }    
}
void input2(){
    for(int i=0;i<m;i++){
        scanf("%lf %lf %lf %lf", &rect[i].x1, &rect[i].y1, &rect[i].x2, &rect[i].y2);
    }
}
void kiemtra(Point cars[], Rect rect[]){
    for(int i=0;i<m;i++){    
        for(int j=0;j<n;j++){
            if(cars[j].x > rect[i].x1 && cars[j].x < rect[i].x2 && cars[j].y < rect[i].y1 && cars[j].y > rect[j].y2){
                count++;
            }
        }
        printf("%d\n", count);
        count = 0;
    }
}
int main(){
    input();
    input2();
    kiemtra(cars,rect);
    return 0;
}