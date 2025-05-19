#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        return 1;
    }

    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double c = atof(argv[3]);


    double delta = b * b - 4 * a * c;


    if (delta > 0) {
        double x1 = (-b + sqrt(delta)) / (2 * a);
        double x2 = (-b - sqrt(delta)) / (2 * a);
        printf("x1 = %.2lf\n", x1);
        printf("x2 = %.2lf\n", x2);
    } else if (delta == 0) {
        double x = -b / (2 * a);
        printf("x1= x2 = %.2lf\n", x);
    } 
    return 0;
}