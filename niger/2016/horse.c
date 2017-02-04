#include <stdio.h>

int main()
{
    int p;
    int l, v;
    int h, m, s, t;

    scanf("%d\n", &p);
    while (p > 0) {
        scanf("%d %d\n", &l, &v);

        t = l / v;
        h = t / 3600;
        m = (t % 3600) / 60;
        s = (t % 3600) % 60;

        printf("%02d:%02d:%02d\n", h, m, s);

        --p;
    }

    return 0;
}
