#include <stdio.h>
#include <string.h>

int main()
{
    int  count, l;
    int  n, p, r;
    char s[21], rep[161];
    char ch;

    scanf("%d\n", &p);
    while (p > 0) {
        scanf("%d %d %s\n", &n, &r, s);

        count = 0;
        l = (int) strlen(s);
        for (int i = 0; i < l; ++i) {
            ch = s[i];
            memset(rep + count, ch, r);
            count += r;
        }
        *(rep + count) = '\0';

        printf("%d %s\n", n, rep);
        --p;
    }

    return 0;
}

