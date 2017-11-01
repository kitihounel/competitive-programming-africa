#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long int i64;

i64 dna[100000];
int sex[100000];

int main()
{
    int  n;
    char s[61];
    i64  f, m, p;

    scanf("%d\n", &n);
    for (int j = 0; j < n; ++j) {
        scanf("%s\n", s);
        sex[j] = s[0] - 48;
        dna[j] = strtoll(s + 1, NULL, 2);
    }

    f = m = 0ll;
    p = (1ll << 59) - 1ll;
    for (int j = 0; j < n - 1; ++j) {
        for (int k = j + 1; k < n; ++k) {
            if ((dna[j] ^ dna[k]) == p) {
                f += sex[j] == sex[k];
                m += sex[j] != sex[k];
            }
        }
    }

    printf("%lld %lld\n", f, m);

    return 0;
}

