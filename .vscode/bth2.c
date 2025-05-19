#include <stdio.h>
int main(){
    float x;
    scanf("%f", &x);
    unsigned char* q =(unsigned char*)&x;
    printf("0x%02X 0x%02X 0x%02X 0x%02X \n",*q,*(q+1),*(q+2),*(q+3));
    return 0;
}