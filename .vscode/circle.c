#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct point {
    double x, y;
} POINT;

typedef struct circle {
    struct point center;
    double radius;
} CIRCLE;

int kiemtra(CIRCLE c, CIRCLE d) {
    double m = sqrt((c.center.x - d.center.x ) * (c.center.x - d.center.x ) + (c.center.y - d.center.y) * (c.center.y - d.center.y));
    return m < (c.radius + d.radius);
}

CIRCLE* hinhtron(int n) {
    CIRCLE* circles = (CIRCLE*) malloc(n * sizeof(CIRCLE));
    return circles;
}

void nhap(CIRCLE* circles, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", i + 1);
        scanf("%lf %lf %lf", &circles[i].center.x, &circles[i].center.y, &circles[i].radius);
    }
}

void random(CIRCLE* circles, int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        circles[i].center.x = rand() % 100;
        circles[i].center.y = rand() % 100;
        circles[i].radius = rand() % 20 + 1;
    }
}

void thongtinhinhtron(CIRCLE* circles, int n) {
    for (int i = 0; i < n; i++) {
        printf("Circle %d: Center (%.2f, %.2f), Radius %.2f\n", i + 1, circles[i].center.x, circles[i].center.y, circles[i].radius);
    }
}

void giaonhieunhat(CIRCLE* circles, int n) {
    int maxIntersections = 0;
    int circleIndex = -1;
    for (int i = 0; i < n; i++) {
        int intersections = 0;
        for (int j = 0; j < n; j++) {
            if (i != j && kiemtra(circles[i], circles[j])) {
                intersections++;
            }
        }
        if (intersections > maxIntersections) {
            maxIntersections = intersections;
            circleIndex = i;
        }
    }
    if (circleIndex != -1) {
        printf(" Circle %d  maxintersection %d \n", circleIndex + 1, maxIntersections);
        for (int j = 0; j < n; j++) {
            if (circleIndex != j && kiemtra(circles[circleIndex], circles[j])) {
                printf("Intersects with Circle %d\n", j + 1);
            }
        }
    }
}

int main() {
    int n;
    int choice;
    scanf("%d", &n);
    CIRCLE* circles = hinhtron(n);
    scanf("%d", &choice);
    if (choice == 1) {
        nhap(circles, n);
    } else if (choice == 2) {
        random(circles, n);
    } else {
        printf("error\n");
        free(circles);
        return 1;
    }

    thongtinhinhtron(circles, n);
    giaonhieunhat(circles, n);

    free(circles);
    return 0;
}
