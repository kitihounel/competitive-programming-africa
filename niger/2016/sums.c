/**
 * Solution provided by the Programming Competence Group of IMSP (Institut de
 * mathématiques et de sciences physiques, Benin).
 */
#include <stdio.h>

int main()
{
    int p;
    long long int n, w;

    scanf("%d\n", &p);
    for (int i = 0; i < p; ++i) {
        scanf("%lld\n", &n);
        w = n * (n + 1) * (n + 2) * (n + 3) / 8;
        printf("%d %lld %lld\n", i + 1, n, w);
    }

    return 0;
}

