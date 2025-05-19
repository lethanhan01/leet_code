#include <stdio.h>
#include <ctype.h>
void CharReadWrite(FILE* fin, FILE* fout)
{
    char c;
    while ((c = fgetc(fin)) != EOF) {
        c = toupper(c);
        fputc(c, fout);
    }
}
int main(int argc, char *argv[]) {
    FILE* fp = fopen(argv[1], "w");
    FILE* tata = fopen(argv[2],"r"); 
    if(fp != NULL && tata != NULL){
            CharReadWrite(tata,fp);
    }
    fclose(fp);
    fclose(tata);
    return 0;
}