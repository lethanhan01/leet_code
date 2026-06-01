#include <stdio.h>
int k, n;
int x[100];

void solution()
{
    for (int i = 1; i <= k; i++)
    {
        printf("%d", x[i]);
    }
    printf("\n");
}

void Try(int i)
{
    for (int v = x[i - 1] + 1; v <= n - k + i; v++)
    {
        x[i] = v;
        if (i == k)
        {
            solution();
        }
        else
        {
            Try(i + 1);
        }
    }
}

int main()
{
    scanf("%d %d", &k, &n);
    x[0] = 0;
    Try(1);
    return 0;
}