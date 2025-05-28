#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int M = 0, N = 0;
int A[100][100] = { 0 };
int B[100][100] = { 0 };
int C[100][100] = { 0 };
int DX[] = {0, 0, -1, 1};
int DY[] = {1, -1, 0, 0};
int MIN_DISTANCE = 1000000;
int DDX[100] = { 0 };
int DDY[100] = { 0 };

void InDD(int d)
{
    printf("%d\n", d);
    for (int i = 0;i < d;i++)
    {
        printf("[%d, %d] ", DDX[i], DDY[i]);
    }
    printf("\n");
}

void Chon(int i, int j, int d)
{
    DDX[d] = i;
    DDY[d] = j;

    if (j == N - 1)
    {
        if (d < MIN_DISTANCE)
        {
            MIN_DISTANCE = d;
        }
    }else
    {
        if (d < MIN_DISTANCE)
        {
            for (int k = 0;k < 4;k++)
            {
                int ni = i + DX[k];
                int nj = j + DY[k];
                if (ni >= 0 && ni < M && nj >= 0 && nj < N)
                {
                    if (A[ni][nj] == 1 && C[ni][nj] == 0)
                    {
                        C[ni][nj] = 1;
                        Chon(ni, nj, d + 1);
                        C[ni][nj] = 0;
                    }
                }
            }
        }
    }
}

void TienXuLy()
{
    for (int i = 0;i < M;i++)
    {
        for (int j = 0;j < N;j++)
        {
            if (A[i][j] == 0)
            {
                for (int k = 0;k < 4;k++)
                {
                    int ni = i + DX[k];
                    int nj = j + DY[k];
                    if (ni >= 0 && ni < M && nj >= 0 && nj < N)
                    {
                        B[ni][nj] = 1;
                    }
                }
            }
        }
    }

    for (int i = 0;i < M;i++)
    {
        for (int j = 0;j < N;j++)
        {
            if (B[i][j] == 1)
            {
                A[i][j] = 0;
            }
        }
    }
}

int main()
{
    scanf("%d %d", &M, &N);
    for (int i = 0;i < M;i++)
    {
        for (int j = 0;j < N;j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    TienXuLy();

    for (int i = 0;i < M;i++)
    {
        if (A[i][0] == 1)
        {
            C[i][0] = 1;
            Chon(i, 0, 0);
            C[i][0] = 0;
        }
    }
    if (MIN_DISTANCE == 1000000)
    {
        MIN_DISTANCE = -1;
    }
    printf("%d", MIN_DISTANCE);
}
