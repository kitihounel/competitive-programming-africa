#include <stdio.h>
#include <string.h>

int count(const char *haystack, const char *needle)
{
    int n = 0;
    const char *tmp;

    tmp = strstr(haystack, needle);
    while (tmp != NULL) {
        ++n;
        tmp = strstr(tmp + 1, needle);
    }

    return n;
}

int main()
{
    int   n, p, t;
    char  s[41];
    const char *sequences[] = {
        "TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT", "HHH"
    };

    scanf("%d\n", &p);
    while (p > 0) {
        scanf("%d %s\n", &t, s);

        printf("%d", t);
        for (int i = 0; i < 8; ++i) {
            n = count(s, sequences[i]);
            printf(" %d", n);
        }
        printf("\n");

        --p;
    }

    return 0;
}
