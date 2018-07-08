/**
 * Number theory theorem: if a = b mod m, then m | (a - b).
 * We are looking for the greatest divisor of (a - b) which is less or equal to M. 
 */
#include <stdio.h>

int main()
{
    int a, b, d, m;

    while (scanf("%d %d %d\n", &a, &b, &m) == 3) {
        d = a - b;
        while (d % m != 0) {
          --m;
        }
        printf("%d\n", m);
    }

    return 0;
}

