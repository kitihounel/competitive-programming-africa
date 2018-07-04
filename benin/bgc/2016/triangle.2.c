/**
 * Solution based on the one presented here:
 * medium.com/lets-code/triangle-trilemma-f1d0dd8b5dbe
 * The program determines the type of a triangle by comparing the lengths of
 * the sides.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct point {
    int x, y;
} point;

/**
 * Compute the (square of the) distance between two points.
 */
int distance(point p, point q)
{
    int dx = q.x - p.x;
    int dy = q.y - p.y;

    return dx * dx + dy * dy;
}

/**
 * Compute the (double of the) area of the triangle formed by 3 points using
 * the determinant method.
 */
int area(point p, point q, point r)
{
    int a = (p.x * q.y - q.x * p.y)
          + (q.x * r.y - r.x * q.y)
          - (p.x * r.y - r.x * p.y);

    return abs(a);
}

int cmp(const void *p, const void *q)
{
    return *((const int *) p) - *((const int *) q);
}

int main()
{
    int    n;
    point  p, q, r;
    bool   isosceles, obtuse, right;

    scanf("%d\n", &n);
    for (int i = 1; i <= n; ++i) {
        printf("Triangle #%d: ", i);
        scanf("%d %d %d %d %d %d\n", &p.x, &p.y, &q.x, &q.y, &r.x, &r.y);

        // If the area of the triangle formed by the 3 points is 0, then the
        // points are aligned.
        if (area(p, q, r) == 0) {
            printf("not a triangle\n");
            continue;
        }

        int sides[] = { distance(p, q), distance(q, r), distance(r, p) };
        qsort(sides, 3, sizeof(int), cmp);

        // Since there is no equilateral triangle in the input, to determine if
        // a triangle id isosceles, we don't need to compare all pairs of sides. 
        isosceles = sides[0] == sides[1] || sides[1] == sides[2];
        obtuse    = sides[0]  + sides[1]  < sides[2];
        right     = sides[0]  + sides[1] == sides[2];

        printf("%s %s triangle\n", isosceles? "isosceles": "scalene",
                                   right? "right": (obtuse? "obtuse": "acute"));
    }

    return 0;
}
