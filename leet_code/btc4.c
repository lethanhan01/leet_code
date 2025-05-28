#include <stdio.h>
int main(){
float n;
scanf("%f",&n);
if(n<4){printf("F");}
else if(n<5 &&n>=4){printf("D");}
else if(n<5.5 && n>=5){printf("D+");}
else if(n<6.5 && n>=5.5){printf("C");}
else if(n<7 && n>=6.5){printf("C+");}
else if(n<8 && n>=7){printf("B");}
else if(n<8.5 && n>=8){printf("B+");}
else if(n<9.5 && n>=8.5){printf("A");}
else {printf("A+");}
return 0;
}