/**
 * Solution found at: www.spoj.com/problems/ANARC08G/cstart=10
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int banks[1000];
    int a, b, n, r, k;

    k = 1;
    while (scanf("%d\n", &n) != 0 && n != 0) {
        memset(banks, 0, 1000 * sizeof(int));

        b = 0;
        for (int u = 0; u < n; ++u) {
            for (int v = 0; v < n; ++v) {
                scanf("%d", &r);
                banks[u] += r;
                banks[v] -= r;
                b += r;
            }
        }

        a = 0;
        for (int j = 0; j < n; ++j) {
            if (banks[j] > 0) {
                a += banks[j];
            }
        }

        printf("%d. %d %d\n", k, b, a);
        ++k;
    }

    return 0;
}

