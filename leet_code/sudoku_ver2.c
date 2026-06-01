#include <stdio.h>

int x[9][9];
int dem = 0;

int check(int r, int c, int v)
{
    // Kiểm tra hàng
    for (int j = 0; j <= 8; j++)
        if (x[r][j] == v)
            return 0;

    // Kiểm tra cột
    for (int i = 0; i <= 8; i++)
        if (x[i][c] == v)
            return 0;

    // Kiểm tra block 3x3
    int rStart = (r / 3) * 3;
    int cStart = (c / 3) * 3;
    for (int i = rStart; i < rStart + 3; i++)
        for (int j = cStart; j < cStart + 3; j++)
            if (x[i][j] == v)
                return 0;

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
    // Nếu hết cột → nhảy sang dòng tiếp theo
    if (c == 9)
    {
        if (r == 8)
        { // nếu đã điền xong ô cuối
            dem++;
            solution();
            return;
        }
        else
        {
            Try(r + 1, 0);
            return;
        }
    }

    // Nếu ô hiện tại đã có sẵn → đi tiếp
    if (x[r][c] != 0)
    {
        Try(r, c + 1);
        return;
    }

    // Thử các giá trị 1..9
    for (int v = 1; v <= 9; v++)
    {
        if (check(r, c, v))
        {
            x[r][c] = v;
            Try(r, c + 1);
            x[r][c] = 0; // backtrack
        }
    }
}

int main()
{
    // Nhập Sudoku
    for (int i = 0; i <= 8; i++)
        for (int j = 0; j <= 8; j++)
            scanf("%d", &x[i][j]);

    Try(0, 0);

    if (dem == 0)
        printf("Khong co loi giai\n");

    return 0;
}
