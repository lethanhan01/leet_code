#include <stdio.h>
#include <string.h>
#include <limits.h>
int kt=0;
int min_diff = INT_MAX;
int max(int a, int b) {
    return (a > b) ? a : b;
}

int main(){
    int n,m;
    int s[1000]={0};
    int v[1000]={0};
    scanf("%d %d", &n, &m);
    for(int i=0; i<n;i++){
        scanf("%d %d", &s[i], &v[i]);
    }
    return 0;
}