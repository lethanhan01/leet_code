#include <stdio.h>
#include <math.h>
int move(int n, int A, int B, int C){
    if(n==1){
        printf("%d %d\n", A, B);
    }
    else{
        move(n-1, A, C, B);
        move(1, A, B, C);
        move(n-1, C, B, A);
    }
}
int main() {
    int n, A,B,C;
    scanf("%d %d %d %d", &n, &A, &B, &C);
    printf("%d\n", (int)pow(2,n)-1);
    move(n, A, B, C);
    return 0;
}