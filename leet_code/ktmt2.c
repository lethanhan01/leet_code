#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void bubble_sort(int* m, int n){
    for(int i =0; i < n; i++){
        for(int j =0; j < n-i; j++){
            if(m[j] > m[j+1]){
                swap(&m[j], &m[j+1]);
            }
        }
    }
}
int result(int* m, int n){
    int flag = 0;
    int k;
    for(int i = 0;i < n; i++){
        if(m[i] % 2 == 1){
            flag = 1;
            k =  m[i-1];
            break;
        }
    }
    return k;
}
int main() {
    int n;
    int m[1000];
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++){
        scanf("%d", &m[i]);
    }
    bubble_sort(m, n);
    printf("%d\n", result(m,n));
    return 0;
}