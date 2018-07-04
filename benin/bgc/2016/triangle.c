/**
 * The program determines the type of a triangle by comparing the lengths of
 * the sides and by using the dot products of all pairs of sides.
 */
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

typedef struct point {
    int x, y;
} point;

typedef struct vector {
    int dx, dy;
} vector;

/**
 * Compute the dot product of two vectors.
 */
int scalarProduct(vector u, vector v)
{
    return v.dx * u.dx + v.dy * u.dy;
}

/**
 * Compute the (square of the) distance between two points.
 */
int distance(point p, point q)
{
    int dx = q.x - p.x;
    int dy = q.y - p.y;

    return dx * dx + dy * dy;
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

        // We check if the three points are aligned by using the slopes of
        // the two line segments [p, q] and [q, r].
        if ( (q.y - p.y) * (r.x - q.x)  == (r.y - q.y) * (q.x - p.x) ) {
            printf("not a triangle\n");
            continue;
        }

        // We buid the 3 vectors.
        vector pq = { dx: q.x - p.x, dy: q.y - p.y };
        vector pr = { dx: r.x - p.x, dy: r.y - p.y };
        vector qp = { dx: p.x - q.x, dy: p.y - q.y };
        vector qr = { dx: r.x - q.x, dy: r.y - q.y };
        vector rp = { dx: p.x - r.x, dy: p.y - r.y };
        vector rq = { dx: q.x - r.x, dy: q.y - r.y };

        isosceles = (distance(p, q) == distance(p, r))
                  | (distance(q, r) == distance(q, p))
                  | (distance(r, p) == distance(r, q));
        obtuse = scalarProduct(pq, pr)  < 0
               | scalarProduct(qp, qr)  < 0
               | scalarProduct(rp, rq)  < 0;
        right  = scalarProduct(pq, pr) == 0
               | scalarProduct(qp, qr) == 0
               | scalarProduct(rp, rq) == 0;

        printf("%s %s triangle\n", isosceles? "isosceles": "scalene",
                                   right? "right": (obtuse? "obtuse": "acute"));
    }

    return 0;
}
