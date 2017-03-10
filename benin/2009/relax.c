/**
 * This problem asks to compute the binomial coefficient nCk with:
 *          n = total number of goals scored by the two teams
 *          k = number of goals scored by the losing team
 * We found the solution in the following thread on stackoverflow:
 * math.stackexchange.com/questions/1159063/how-many-ways-to-reach-a-given-tennis-score.
 *
 * Note: the number of possibilities is equal to the total number of goals
 *       scored if one or both teams score one goal.
 */
#include <stdio.h>
#include <stdint.h>

/* We need to store the factorials of numbers from 0 to 20. */
/* We can use 64-bit unsigned integers. */
typedef unsigned long long int ui64;
ui64    factorials[21];

/**
 * Returns the minimum of two integers.
 */
int min(int a, int b)
{
    return (a > b? b: a);
}

/**
 * Compute the binomial coefficient nCk.
 * The following conditions (based on the problem statement) are required:
 *              0 < n <= 20 and 0 <= k <= 10.
 */
ui64 nChooseK(int n, int k)
{
    return k == 0? 1ull: factorials[n] / factorials[n - k] / factorials[k];
}

int main()
{
    int  a, b;
    ui64 n;

    /* Pre-computes the factorials of numbers from 0 to 20. */
    factorials[0] = 1ull;
    for (int i = 1; i <= 20; ++i) {
        factorials[i] = factorials[i - 1] * (ui64) i;
    }

    while (scanf("%d %d\n", &a, &b) && a != -1) {
        if (a == 0 && b == 0) {
            printf("%d+%d!=1\n", a, b);
        } else if (a == 1 || b == 1) {
            printf("%d+%d=%d\n", a, b, a + b);
        } else {
            n = nChooseK(a + b, min(a, b));
            printf("%d+%d!=%llu\n", a, b, n);
        }
    }
}
