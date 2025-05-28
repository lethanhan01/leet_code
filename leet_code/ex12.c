#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
typedef struct _sinhvien
{
    char hoten[31];
    float toan;
    float ly;
    float hoa;
} SINHVIEN;

SINHVIEN sv[10];
int main()
{
    //Nhap
    for (int i = 0;i < 10;i ++)
    {

    }
    //Ghi
    FILE* f = fopen("SV.DAT","wb");
    for (int i = 0;i < 10;i++)
    {

    }
    fclose(f);
    //Doc
    int i = 0;
    scanf("%d", &i);
    f = fopen("SV.DAT","rb");
    //Doc ra thong tin sv i va in ra man hinh
    fclsoe(f);
    //Sua ten sinh vien va ghi lai
    f = fopen("SV.DAT","ab");
    fseek(f, i * sizeof(SINHVIEN), SEEK_SET);
    
    fclose(f);
}