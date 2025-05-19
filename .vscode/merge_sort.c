#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
int n = 0;
int a[100005] = { 0 };
int t[100005] = { 0 };

void merge(int a[], int L, int R, int M)
{
    int k = L;
    int i = L;
    int j = M + 1;
    while (k <= R)
    {
        if (i > M)
        {
            t[k] = a[j];
            j++;
        }else if (j > R)
        {
            t[k] = a[i];
            i++;
        }else
        {
            if (a[i] <= a[j])
            {
                t[k] = a[i];
                i++;
            }else
            {
                t[k] = a[j];
                j++;
            }
        }
        k++;
    }
    memcpy(a + L, t + L, (R - L + 1) * sizeof(int));
}

void mergesort(int a[], int L, int R)
{
    if (L < R)
    {
        int M = (L + R) / 2;
        mergesort(a, L, M);
        mergesort(a, M + 1, R);
        merge(a, L, R, M);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0;i < n;i++)
    {
        scanf("%d", &a[i]);
    }
    mergesort(a, 0, n - 1);
    for (int i = 0;i < n;i++)
    {
        printf("%d ", a[i]);
    }
}
