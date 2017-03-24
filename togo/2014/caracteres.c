#include <stdio.h>
#include <string.h>

int main()
{
    int  count, l;
    int  n, p, r;
    char s[21], t[161];
    char ch;

    scanf("%d\n", &p);
    while (p > 0) {
        scanf("%d %d %s\n", &n, &r, s);

        count = 0;
        l = (int) strlen(s);
        for (int i = 0; i < l; ++i) {
            ch = s[i];
            memset(t + count, ch, r);
            count += r;
        }
       *(t + count) = '\0';

        printf("%d %s\n", n, t);
        --p;
    }

    return 0;
}

