#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int N = 0;
int H[32] = { 0 };
int Finish = 0;

int Ktra(int i, int r)
{
    for (int k = 0;k < i;k++)
    {
        if (H[k] == r)
            return 0;
        if (H[k] - k == r - i)
            return 0;
        if (H[k] + k == r + i)
            return 0;
    }
    return 1;
}

void InKQ()
{
    for (int i = 0;i < N;i++)
    {
        printf("%d", H[i] + 1);
    }
    printf("\n");
}

void Chon(int i)
{
    if (i < N)
    {
        for (int k = 0;k < N; k++)
        {
            if (Ktra(i, k))
            {
                H[i] = k;
                Chon(i + 1);
            }
        }
    }else
    {
        InKQ();
    }
}

int main()
{
    scanf("%d", &N);
    Chon(0);
}
