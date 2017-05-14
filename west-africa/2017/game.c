/**
 * Solution found at github.com/saadtaame/acpc/blob/master/2014/A.cc.
 *
 * Note: during the contest, we asked the judges if this problem can be
 * solved using 32-bit integers. He asked yes. But the fact is that it is
 * impossible to solve this problem using 32-bit integers.
 * Take an edge case, for example: N = 1000, Y = 1000, N = 70 and M = 100000,
 * declare all variables as 32-bit integers and print the values of the
 * containers during the cloning operation... There will be integer overflow.
 * We mention this because the C/C++ compiler used by the judge does not enable
 * to use 64-bit integers. So this problem could be solved only by using Java.
 */
#include <stdio.h>

typedef long long int i64;

i64 gcd(i64 a, i64 b)
{
    i64 r;

    while (b != 0ll) {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    i64 a, b;
    i64 n, m, x, y;
    int t;

    scanf("%d\n", &t);
    for (int i = 1; i <= t; ++i) {
        scanf("%lld %lld %lld %lld\n", &x, &n, &y, &m);
        a = x;
        b = 0;
        // fprintf(stderr, "Test case %d: a = %lld, b = %lld\n", i, a, b);
        while (n > 0ll) {
            if (a > b) {
                b += a;
            } else {
                a += b;
            }
            // fprintf(stderr, "Round %lld: a = %lld, b = %lld\n", n, a, b);
            --n;
        }
        if (a > b) {
            a += y;
        } else {
            b += y;
        }
        printf("Case %d: %lld\n", i, gcd(a, b));
    }

    return 0;
}
