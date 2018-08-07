/**
 * The number of diagonals in an n-gon (n >= 3) is given by the formula:
 *      D = (n-1) * (n-2) * ... * 1 - n = (n * (n-1) / 2) - n
 * To find n, we have to solve the equation:
 *      (1/2 * n^2) - (3/2 * n) - D = 0
 */
#include <stdio.h>
#include <math.h>

typedef long long int i64;

int main()
{
    i64 n, ans;
    long double delta;
    int t;

    t = 1;
    while (scanf("%lld\n", &n) == 1 && n != 0) {
        delta = 9.0L / 4 + 2.0L * n;
        ans = ceill(1.5L + sqrt(delta));
        printf("Case %d: %lld\n", t, ans);
        ++t;
    }

    return 0;
}

