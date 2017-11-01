#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n, r, s;

    while (scanf("%d\n", &n) > 0) {
        s = n * (n + 1) * (2 * n + 1) / 6;
        r = n * n * (n + 1) * (n + 1) / 4;
        printf("%d %d\n", s, max(1, r));
    }

    return 0;
}

