#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char x[1024] = { 0 };

int Dem(int start, int end)
{
    if (start > end)
        return 0;
    else if (start == end)
        return 1;
    else
    {
        int tmp1 = Dem(start + 1, end);
        int tmp2 = Dem(start, end - 1);
        int tmp3 = Dem(start + 1, end - 1);
        int tmp = tmp1 + tmp2 - tmp3;
        if (x[start] == x[end])
            return tmp + 1;
        else
            return tmp;
    }
}

int main()
{
    scanf("%s", x);
    printf("%d", Dem(0, strlen(x) - 1));
}
