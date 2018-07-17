#include <stdio.h>
#include <stdlib.h>

#define MAX_N 12

int cmp(const void *p1, const void *p2)
{
    int a = *(const int*) p1;
    int b = *(const int*) p2;

    return b - a;
}

int max(int a, int b)
{
    return (a > b ? a : b);
}

int main()
{
    int needs[MAX_N], kits[MAX_N], unused[MAX_N];
    int n, g, k;
    int q;

    scanf("%d", &n);
    while (n != 0) {
        k = 0;
        for (int j = 0; j < n; ++j) {
            scanf("%d", needs + j);
            kits[j] = needs[j] / 50 + (needs[j] % 50 != 0 ? 1 : 0);
            k = max(k, kits[j]);
        }
        scanf("%d", &g);

        for (int j = 0; j < n; ++j) {
            unused[j] = k * 50 - needs[j];
        }

        while (g > 0) {
            qsort(unused, n, sizeof(int), cmp);
            --g;
            --unused[0];
            --unused[1];
            --unused[2];
        }

        if (unused[2] < 0) {
            q  = abs(unused[2]);
            k += (q / 50) + (q % 50 != 0 ? 1 : 0);
        }

        printf("%d\n", k);
        scanf("%d", &n);
    }

    return 0;
}
