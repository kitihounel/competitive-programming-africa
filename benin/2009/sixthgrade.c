/**
 * This problem asks to compute the greatest common divisor (GCD) and the least
 * common multiple (LMC) of two integers.
 * For two positive integers a et b, the following equality always holds:
 *      a * b = GCD(a, b) * LCM(a, b)
 * So all we have to do is to compute the GCD using Euclid's algorithm and we
 * will be abble to deduce the LCM.
 */
#include <stdio.h>

/**
 * Compute the GCD of two positive integers.
 */
int gcd(int a, int b)
{
    int r;

    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    int a, b, d, m;
    int i, n;

    scanf("%d\n", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d %d\n", &a, &b);
        d = gcd(a, b);
        // To compute the LCM, always divide a by the GCD before multiply by b.
        m = a / d * b;
        printf("%d %d %d\n", i + 1, m, d);
    }

    return 0;
}
