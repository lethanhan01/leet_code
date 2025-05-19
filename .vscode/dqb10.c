#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int M = 0, N = 0;
int A[1000] = { 0 };

void InKQ()
{
    for (int i = 0;i < N;i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void Chon(int i, int S)
{
    if (i == N)
    {
        if (S == M)
        {
            InKQ();
        }
    }else
    {
        int tmp = N - i - 1; //So phan tu con phai chon
        for (int v = 1; v <= M - S - tmp;v++)
        {
            A[i] = v;
            Chon(i + 1, S + v);
        }
    }
}

int main()
{
    scanf("%d%d", &N, &M);
    Chon(0, 0);
}
