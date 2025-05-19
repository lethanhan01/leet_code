#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int N = 0;
int S[1001] = { 0 };
int V[1001] = { 0 };
int M = 0;

int Chon(int i, int v, int m)
{
    if (i == N)
    {
        return v;
    }else
    {
        if (S[i] <= m)
        {
            int kq1 = Chon(i + 1, v + V[i], m - S[i]);
            int kq2 = Chon(i + 1, v, m);
            return kq1 > kq2 ? kq1 : kq2;
        }else
            return Chon(i + 1, v, m);
    }
}

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0;i < N;i++)
    {
        scanf("%d %d", &S[i], &V[i]);
    }
    printf("%d", Chon(0, 0, M));
}
