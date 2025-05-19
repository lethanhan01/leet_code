#include <stdio.h>
int Tiendien(int sodien){
    if(sodien < 250){
        return sodien*2000;
    }else if(sodien < 400){
        return (sodien -250)*3000 + 250*2000;
    }
    else if(sodien < 500){
        return (sodien - 400 )*4000 + 250*2000+ 150*3000; 
    }
    else{
        return (sodien - 500)*5000 + 100*4000 + 150*3000 + 250*2000;
    }
}
int nhapso(){
    int n;
    scanf("%d", &n);
    return n;
}
int main() {
    int i =0;
    long min = 1e18;
    int m;
    int a;
    for(i =0; i< 10; i++){
        if(a == -1){
            break;
        }else{
            a = nhapso();
            if(Tiendien(a) < min){
                min = (long)Tiendien(a);
                m = a;
            }
        }
    }
    printf("%lld %d\n", min, m);
    return 0;
}
