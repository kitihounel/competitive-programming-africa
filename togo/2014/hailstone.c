#include <stdio.h>

int main()
{
    int p, t;
    long long int n, max;

    scanf("%d\n", &p);
    while (p > 0) {
        scanf("%d %lld\n", &t, &n);

        max = n;
        if (n & (n - 1) != 0ll) {
            while (n != 1ll) {
                n = (n % 2ll == 0ll? n / 2ll: 3ll * n + 1ll);
                if (n > max) {
                    max = n;
                }
            }
        }

        printf("%d %lld\n", t, max);
        --p;
    }

    return 0;
}

