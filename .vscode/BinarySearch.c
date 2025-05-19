#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
typedef struct
{
    int value;
    int index;
}PAIR;

int a[100001] = { 0 };
PAIR b[100001] = { 0 };
PAIR t[100001] = { 0 };
int n;

int compare(PAIR p, PAIR q)
{
    if (p.index == q.index && p.value == q.value)
        return 0;
    else
    {
        if (p.value < q.value)
            return -1;
        else if (p.value > q.value)
            return 1;
        else{
            if (p.index < q.index)
                return -1;
            else
                return 1;
        }
    }
}

void merge(PAIR x[], int L, int R, int M)
{
    int k = L;
    int i = L;
    int j = M + 1;
    while (k <= R)
    {
        if (i > M)
        {
            t[k] = x[j];
            j++;
        }else if (j > R)
        {
            t[k] = x[i];
            i++;
        }else
        {
            if (compare(x[i], x[j]) <= 0)
            {
                t[k] = x[i];
                i++;
            }else
            {
                t[k] = x[j];
                j++;
            }
        }
        k++;
    }
    memcpy(x + L, t + L, (R - L + 1) * sizeof(PAIR));
}

void mergesort(PAIR x[], int L, int R)
{
    if (L < R)
    {
        int M = (L + R) / 2;
        mergesort(x, L, M);
        mergesort(x, M + 1, R);
        merge(x, L, R, M);
    }
}

int lower_bound(PAIR x[], int n, int v)
{
    int L = 0;
    int R = n - 1;

    while (L < R - 1)
    {
        int M = (L + R) / 2;
        if (x[M].value < v)
            L = M + 1;
        else
            R = M;
    }

    if (L == R - 1)
    {
        if (x[L].value >= v)
            return L;
        else if (x[R].value >= v)
            return R;
        else
            return -1;
    }

    if (L == R)
    {
        if (x[L].value >= v)
            return L;
        else
            return -1;
    }
}

int upper_bound(PAIR x[], int n, int v)
{
    int L = 0;
    int R = n - 1;

    while (L < R - 1)
    {
        int M = (L + R) / 2;
        if (x[M].value <= v)
            L = M + 1;
        else
            R = M;
    }

    if (L == R - 1)
    {
        if (x[L].value > v)
            return L;
        else if (x[R].value > v)
            return R;
        else
            return -1;
    }

    if (L == R)
    {
        if (x[L].value > v)
            return L;
        else
            return -1;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0;i < n;i++)
    {
        scanf("%d", &a[i]);
        b[i].value = a[i];
        b[i].index = i;
    }
    mergesort(b, 0, n - 1);
    for (int i = 0;i < n;i++)
    {
        int j = lower_bound(b, n, a[i]);
        if (b[j].value == a[i])
        {
            if (b[j].index < i)
                printf("1\n");
            else
                printf("0\n");
        }else
            printf("0\n");
    }
    return 0;
}
