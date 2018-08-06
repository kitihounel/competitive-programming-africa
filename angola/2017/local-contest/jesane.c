/**
 * This problem is easier than it seems.
 * The trick is that 1 / (sqrt(a) + sqrt(a+1)) = sqrt(a+1) - sqrt(a)
 * By using that in the sequence, we obtain a colliding sum that reduces to
 *      S = sqrt(n+1) - 1 => n = (S+1)^2 - 1
 */
#include <stdio.h>

typedef long long int i64;

int main()
{
    int t;
    i64 n, s;

    scanf("%d\n", &t);
    while (t != 0) {
        scanf("%lld\n", &s);
        printf("%lld\n", (s + 1ll) * (s + 1ll) - 1ll);
        --t;
    }

    return 0;
}

