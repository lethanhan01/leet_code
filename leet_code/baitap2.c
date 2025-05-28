#include <stdio.h>
enum { SUCCESS, FAIL };
void CharReadWrite(FILE* fin, FILE* fout)
{
    int c;
    while ((c = fgetc(fin)) != EOF) {
        fputc(c, fout);
    }
}
int main( int argc,char** argv ){
    char ch;
    int c;
   if (argc >=3 ){
    char* scrName= argv[1];
    char* dstName= argv[2];
    FILE* srcf = fopen(scrName,"a");
    FILE* dstf = fopen(dstName, "r");
    if(srcf != NULL && dstf != NULL){
            CharReadWrite(dstf,srcf);
            fclose(srcf);
            fclose(dstf);
        }
        else if(srcf == NULL){
            printf("Cannot open %s\n",scrName);
        }
        else if(dstf == NULL){
            printf("Cannot open %s\n",dstName);
        }
    }
    return 0;
}