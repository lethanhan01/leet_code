#include <stdio.h>
#include <string.h>
int countwords(char* line){
    char s[256] ={0};
    int m=0;
    int i=0;
    while(i<strlen(line)){
        if(
            line[i]!=' ' &&
            line[i]!='\t'&&
            line[i]!='\r'&&
            line[i]!='\n'
            ){
                sprintf(s+strlen(s),"%c",line[i]);
            }
        else{
            if(strlen(s)>0){
                m++;
                memset(s,sizeof(s),0);
            }
        }
        i++;
   }
   return m;
}
int main(){
    char line[100000];
    scanf("%s",line);
    printf("%d", countwords(line));
    return 0;
}