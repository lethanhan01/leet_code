#include <stdio.h>
void chuyen(int m) {
    if(m /60 == 0) {
        printf("%d phut \n", m);
    } else {
        printf(" %d gio, %d phut", m/60, m%60);
    }
}
int main() {
    int m;
    scanf("%d", &m);
    chuyen(m);
    return 0;
}