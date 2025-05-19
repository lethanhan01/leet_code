#include <stdio.h>
#include <stdlib.h>
int n=0, M=0;
int X[10000]={0};
void inKQ(){
    for(int i=0;i<n;i++){
        printf("%d", X[i]);
    }
    printf("\n");
}
void Chon(int i, int S){
    if(i == n){
        if(S==M){}
        inKQ();
    }
    else{
        int tmp = n-i-1;
        for(int v=1; v <= M-S-tmp; v++){
            X[i] = v;
            Chon(i+1,S+v);
        } 
    }


}
int main(){
    scanf("%d %d", &n, &M);

}