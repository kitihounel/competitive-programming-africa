/**
 * This problem asks to compute the sum of the N first squares. There is a well
 * known formula for that. Since n can reach 999,999 we have to use 64-bit
 * integers.
 */
#include <stdio.h>

int main()
{
    int p;
    long long int l;

    scanf("%d\n", &p);
    while(p > 0) {
        scanf("%lld\n", &l);
        printf("%lld\n", l * (l + 1ll) * (2ll * l + 1ll) / 6ll);
        --p;
    }

    return 0;
}

