#include <stdio.h>
#include <stdlib.h>
int N = 0;
char kq[1024] = { 0 };

void InKQ()
{
    for (int i = 0;i < N;i++)
    {
        printf("%d", kq[i]);
    }
    printf("\n");
}

void Sinh(int k)
{
    for (int v = 0;v <= 1;v++)
    {
        if (k == 0 || (k > 0 && kq[k-1] + v <= 1))
        {
            kq[k] = v;
            if (k == N - 1)
            {
                InKQ();
            }else
                Sinh(k+1);
        }
    }
}

int main()
{
    scanf("%d", &N);
    Sinh(0);
    return 0;
}
