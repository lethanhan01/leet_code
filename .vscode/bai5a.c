#include <stdio.h>
#include <string.h>
int main(){
    char s[1000000];
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++){
         if(
            s[i]!=' ' &&
            s[i]!='\t'&&
            s[i]!='\r'&&
            s[i]!='\n'&&
            s[i]>='a' && 
            s[i]<='z')
            {
            s[i]-=32;
            }
        }
    printf("%s",s);
    return 0;
}