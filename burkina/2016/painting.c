#include <stdio.h>
#include <stdlib.h>

/**
 * Return the maximum of two integers.
 */
int max(int a, int b)
{
    return (a > b? a: b);
}

/**
 * Find the maximum element in an array.
 */
int maxElement(int n, int a[n])
{
    int m;

    m = a[0];
    for (int i = 1; i < n; ++i) {
        m = max(m, a[i]);
    }

    return m;
}

/**
 * Comparison function used by the qsort function.
 */
int compare(const void *a, const void *b)
{
    return *((const int *) a) - *((const int *) b);
}

int main()
{
    int g, m, n;
    int q, r;
    int grayBottleCount, mixCount, packCount;
    int bottles[12], quantities[12];

    while (scanf("%d", &n) > 0 && n != 0) {
        r = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &q);
            if (q > 0) {
                quantities[r] = q;
                bottles[r] = (quantities[r] / 50) + ((quantities[r] % 50 != 0)? 1: 0);
                ++r;
            }
        }
        scanf("%d", &g);

        m = maxElement(r, bottles);
        mixCount = 0;
        if (r > 3) {
            /* Compute the number of mixes that can be made. */
            /* This idea is stolen from the official solution. :) */
            qsort(bottles, r, sizeof(int), compare);
            while (bottles[2] < m) {
                ++mixCount;
                ++bottles[0];
                ++bottles[1];
                ++bottles[2];
                qsort(bottles, n, sizeof(int),compare);
            }
        }

        packCount = m;
        grayBottleCount = (g / 50) + ((g % 50 != 0)? 1: 0) - mixCount;
        if (grayBottleCount > 0) {
            int extraPackCount = (grayBottleCount / 4) + ((grayBottleCount % 4 != 0)? 1: 0);
            packCount += extraPackCount;
        }

        printf("%d\n", packCount);
        
    }

    return 0;
}

