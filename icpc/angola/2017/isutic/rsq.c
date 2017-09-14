#include <stdio.h>
#include <string.h>

#define N 100000

typedef long long int i64;

int main()
{
    int t, n, q;
    int lo, hi;
    i64 v;
    i64 numbers[N], sums[N];

    scanf("%d\n", &t);
    for (int j = 0; j < t; ++j) {
        scanf("%d %d\n", &n, &q);

        memset(numbers, 0, N * sizeof(i64));
        memset(sums, 0, N * sizeof(i64));
        for (int i = 0; i < n; ++i) {
            scanf("%lld", numbers + i);
            sums[i] = (i == 0 ? numbers[i] : sums[i - 1] + numbers[i]);
        }

        // Blank line between test cases.
        if (j != 0) {
            printf("\n");
        }

        for (int i = 0; i < q; ++i) {
            scanf("%d %d\n", &lo, &hi);
            v = sums[hi] - (lo > 0 ? sums[lo - 1] : 0);
            printf("%lld\n", v);
        }
    }

    return 0;
}

