#include <stdio.h>
#include <math.h>

typedef struct point
{
    double x, y;
} POINT;

struct circle
{
    struct point center;
    double radius;
};

typedef struct circle CIRCLE;
int kiemtra(CIRCLE c, CIRCLE d)
{
    double m = sqrt((c.center.x - d.center.x ) * (c.center.x - d.center.x ) + (c.center.y - c.center.y) * (c.center.y - c.center.y));
    return m < c.radius;
}
int main(){
    CIRCLE c;
    CIRCLE d;
    scanf("%lf%lf", &c.center.x, &c.center.y);
    scanf("%lf", &c.radius);
    scanf("%lf%lf", &d.center.x, &d.center.y);
    scanf("%lf", &d.radius);
    if (kiemtra(c, d)){
        printf("YES\n");
    }
    else
        printf("NO\n");
    return 0;
}
