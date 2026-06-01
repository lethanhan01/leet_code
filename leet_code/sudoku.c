#include <stdio.h>
int x[9][9], dem = 0;
int check(int r, int c, int v)
{
    for (int j = 0; j <= c - 1; j++)
        if (x[r][j] == v)
            return 0;
    for (int i = 0; i <= r - 1; i++)
        if (x[i][c] == v)
            return 0;
    int rStart = 3 * (r / 3);
    int cStart = 3 * (c / 3);
    // Checkcácô trong lưới3x3 củaô (dòngr, cột c):
    // a.Các ô (i1,j1) thuộc dòng trước dòngr:
    for (int i1 = rStart; i1 <= r - 1; i1++)
        for (int j1 = 0; j1 <= 2; j1++)
            if (x[i1][cStart + j1] == v)
                return 0;
    // b.Các ô (i1, j1) thuộc dòng r,trướcô(r, c):
    for (int j1 = cStart; j1 <= c - 1; j1++)
        if (x[r][j1] == v)
        {
            return 0;
        }
    return 1;
}
void solution()
{
    printf("Cach dien thu %d:\n", dem);
    for (int i = 0; i <= 8; i++)
    {
        for (int j = 0; j <= 8; j++)
            printf("%d ", x[i][j]);
        printf("\n");
    }
    printf("\n");
}
void Try(int r, int c)
{
    for (int v = 1; v <= 9; v++)
    {
        if (check(r, c, v))
        {
            x[r][c] = v;
            if (r == 8 && c == 8)
            {
                dem++;
                solution();
            }
            else
            {
                if (c == 8)
                    Try(r + 1, 0);
                else
                    Try(r, c + 1);
            }
        }
    }
}
int main()
{
    Try(0, 0);
    if (dem == 0)
        printf("Khong co loi giai");
    return 0;
}
