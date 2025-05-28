#include <stdio.h>
 void doi(char *mao)
 {
     if(mao[0]>='a'&&mao[0]<='z')
     {
         mao[0]=mao[0]-'a'+'A';
     }
 }
int main()
{
    const char *mao[] = {"the", "a", "one", "some", "any"};
    const char *danh[] = {"boy", "girl", "dog", "town", "car"};
    const char *dong[] = {"drove", "jumped", "ran", "walked", "skipped"};
    const char *gioi[] = {"to", "from", "over", "under", "on"};
    int n=5;
    srand(NULL);
    for(int i=0;i<10;i++)
    {
        const char* mao1=mao[rand()%n];
        const char* mao2=mao[rand()%n];
        const char* danh1=danh[rand()%n];
        const char* danh2=danh[rand()%n];
        const char* dong1=dong[rand()%n];
        char mao3[10];
        strcpy(mao3,mao1);
        doi(&mao3);
        printf("%s %s %s %s %s.",mao3,danh1,dong1,mao2,danh2);
        printf("\n");

    }

    return 0;
}
