/**
 * Ad hoc problem. Compute the distance between the given color and each of the
 * primary colors and choose the closest one.
 *
 * Note: If we find a primary color which distance gives 0, we choose it and
 * stop the search.
 */
#include <stdio.h>

typedef struct color {
    int r, g, b;
} COLOR;

int distance(COLOR c1, COLOR c2)
{
    int dr, dg, db;

    dr = c1.r - c2.r;
    dg = c1.g - c2.g;
    db = c1.b - c2.b;

    return dr * dr + dg * dg + db * db;
}

int main()
{
    COLOR  primary[16];
    COLOR  c;
    int dist;
    int i, j; // i will be used to loop over the primary colors.
              // j will hold the index of the associated primary color.

    // We get primary colors.
    for(i = 0; i < 16; ++i) {
        scanf("%d %d %d\n", &primary[i].r, &primary[i].g, &primary[i].b);
    }

    while(scanf("%d %d %d\n", &c.r, &c.g, &c.b) == 3  && c.r > -1) {
        dist = distance(c, primary[0]);
        j = 0;
        for(i = 1; i < 16 && dist != 0; ++i) {
            int  tmp = distance(c, primary[i]);
            if(tmp < dist) {
                j = i;
                dist = tmp;
            }
        }

        printf("(%d,%d,%d) est associe a (%d,%d,%d)\n", c.r, c.g, c.b, \
               primary[j].r, primary[j].g, primary[j].b);
    }

    return 0;
}

