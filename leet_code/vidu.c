#include <stdio.h>
char* substr(const char* s, int offset, int number){
    int len= (s==NULL? 0: strlen(s));
    if( offset >=0 && offset < len )
    {
        char* result = (char*)calloc(number+1, sizeof(char));
        if(result != NULL){
            strncpy(result, s + offset, number);
            return result;
        }
    }
}
int main(){
    char* p=substr("Hello world",1,5);
    if(p!= NULL){
    printf("%s",p);
    p = NULL;
    }
    return 0;
}