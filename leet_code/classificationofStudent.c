#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
typedef char STRING[101];

int n = 0;
STRING a[100005];
int b[100005] = { 0 };
STRING c[100005];
int t[100005] = { 0 };
int d[100005] = { 0 };
int e[100005] = { 0 };
int f[100005] = { 0 };
int g[100005] = { 0 };
void QuickSort(STRING a[], int L, int R)
{
    if (L < R)
    {
        STRING pivot, tmp;
        int pivot_index = R;
        strcpy(pivot, a[pivot_index]);
        int i = L - 1;
        for (int j = L;j <= R;j++)
        {
            if (strcmp(a[j], pivot) < 0)
            {
                i++;
                strcpy(tmp, a[i]);
                strcpy(a[i], a[j]);
                strcpy(a[j], tmp);
            }
        }
        i++;
        strcpy(tmp, a[i]);
        strcpy(a[i], a[pivot_index]);
        strcpy(a[pivot_index], tmp);
        QuickSort(a, L, i - 1);
        QuickSort(a, i + 1, R);
    }
} 
void merge(int b[], int L, int R, int M)
{
    int k = L;
    int i = L;
    int j = M + 1;
    while (k <= R)
    {
        if (i > M)
        {
            t[k] = b[j];
            j++;
        }else if (j > R)
        {
            t[k] = b[i];
            i++;
        }else
        {
            if (b[i] <= b[j])
            {
                t[k] = b[i];
                i++;
            }else
            {
                t[k] = b[j];
                j++;
            }
        }
        k++;
    }
    memcpy(b + L, t + L, (R - L + 1) * sizeof(int));
}

void mergesort(int b[], int L, int R)
{
    if (L < R)
    {
        int M = (L + R) / 2;
        mergesort(b, L, M);
        mergesort(b, M + 1, R);
        merge(b, L, R, M);
    }
}
void sapxep(STRING a[], STRING c[], int d[],int e[], int n){
    int i=0;
    int j=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(strcmp(a[i],c[j])==0){
                e[i]=d[j];
            }
        }
    }
}
void sapxep2(int b[], int e[],int g[],int f[], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(b[i]==e[j]){
                f[j]=g[i];
            }
        }
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 0;i < n;i++)
    {
        scanf("%s %d", a[i], &b[i]);
    }
    for(int i=0;i<n;i++){
        strcpy(c[i],a[i]);
        d[i]=b[i];
    }
    for(int i=0;i<n;i++){
        g[i]=i;
    }
    QuickSort(a, 0, n - 1);
    mergesort(b, 0, n - 1);
    sapxep(a,c,d,e,n);
    /*for(int i=0;i<n;i++){
        printf("%s %d\n",a[i],e[i]);
    }*/
    sapxep2(b,e,g,f,n);
    for (int i = 0;i < n;i++)
    {
        printf("%s %d\n", a[i], f[i]);
    }
}
