#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
typedef char STRING[101];

int n = 0;
STRING a[100005];

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

int main()
{
    scanf("%d", &n);
    for (int i = 0;i < n;i++)
    {
        scanf("%s", a[i]);
    }
    QuickSort(a, 0, n - 1);
    for (int i = 0;i < n;i++)
    {
        printf("%s\n", a[i]);
    }
}
