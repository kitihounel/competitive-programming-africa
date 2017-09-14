/**
 * Since bin(8000) = 1111101000000, we only need the 13 first powers of 5, i.e.
 * 5^0 to 5^12. But in this problem, 1 is not in the set of the powers of 5,
 * so will use powers starting from 5^1 to 5^13.
 */

#include <stdio.h>

int main()
{
    int powers[13];
    int luckyNumber, n, t;

    powers[0] = 5;
    for (int j = 1; j < 13; ++j) {
        powers[j] = powers[j - 1] * 5;
    }

    scanf("%d\n", &t);
    while (t > 0) {
        scanf("%d\n", &n);
        luckyNumber = 0;
        for (int i = 0; i < 13; ++i) {
            if (n & (1 << i)) {
               luckyNumber += powers[i];
            }
        }
        printf("%d\n", luckyNumber);
        --t;
    }

    return 0;
}

