#include <stdio.h>
#include <string.h>

int main(void)
{
    int  p;
    int  m, n, x, y;
    char s[3], t[3];


    scanf("%d\n", &p);
    while(p > 0) {
        scanf("%*s %d %s %*s %d %s\n", &m, s, &n, t);

        x = (((s[0] - 'A') * 10) + (s[1] - 'A')) * 9999 + m;
        y = (((t[0] - 'A') * 10) + (t[1] - 'A')) * 9999 + n;
        printf("%d\n", y - x + 1);

        --p;
    }

    return 0;
}

