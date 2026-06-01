#include <stdio.h>
#include <math.h>
double f(double x){
    return pow(x, 4) - 3 * pow(x, 3) + 2 * pow(x, 2) - x + 5;
}
double dfx(double x){
    return 4 * pow(x, 3) - 9 * pow(x, 2) + 4 * x - 1;
}
double saiPhanThuan(double x, double a, double b, double h){
    return (f(x + h) - f(x)) / h;
}
double saiPhanNghich(double x, double a, double b, double h){
    return (f(x) - f(x - h)) / h;
}
double saiPhanTrung(double x, double a, double b, double h){
    return (f(x + h) - f(x - h)) / (2 * h);
}
int main(){
    double a, b, x, h;
    printf("Nhap a, b (khoang can tinh dao ham): ");
    scanf("%lf%lf", &a, &b);
    printf("Nhap x (diem can tinh dao ham): ");
    scanf("%lf", &x);
    printf("Nhap h (buoc sai phan): ");
    scanf("%lf", &h);
    if(x < a || x > b){
        printf("Gia tri x khong nam trong khoang [%lf, %lf]\n", a, b);
        return 1;
    }
    printf("Dao ham tai x = %lf theo cong thuc sai phan thuan: %lf\n", x, saiPhanThuan(x, a, b, h));
    printf("Dao ham tai x = %lf theo cong thuc sai phan nghich: %lf\n", x, saiPhanNghich(x, a, b, h));
    printf("Dao ham tai x = %lf theo cong thuc sai phan trung: %lf\n", x, saiPhanTrung(x, a, b, h));
    printf("Dao ham tai x = %lf theo cong thuc chinh xac: %lf\n", x, dfx(x));
    return 0;
}