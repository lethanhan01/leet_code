#include <stdio.h>

typedef struct {
    double x, y;
} Point;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Point cars[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &cars[i].x, &cars[i].y);
    }

    for (int i = 0; i < m; i++) {
        double x1, y1, x2, y2;
        scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
        int count = 0;

        for (int j = 0; j < n; j++) {
            if (cars[j].x > x1 && cars[j].x < x2 && cars[j].y < y1 && cars[j].y > y2) {
                count++;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}
