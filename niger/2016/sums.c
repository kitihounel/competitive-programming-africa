/**
 * Solution provided by the Programming Competence Group of IMSP (Institut de
 * mathématiques et de sciences physiques - Dangbo(Benin)).
 */
#include <stdio.h>

int main()
{
    int p;
    long long int n, w;

    scanf("%d\n", &p);
    for (int i = 0; i < p; ++i) {
        scanf("%lld\n", &n);
        w = (n * (n + 1) / 2) * ((n * (n + 1) / 2) + (2 * n + 1) + 2) / 2;
        printf("%d %lld %lld\n", i + 1, n, w);
    }

    return 0;
}

