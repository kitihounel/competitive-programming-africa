#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return (a > b? a: b);
}

int min(int a, int b)
{
    return (a > b? b: a);
}

int main()
{
    int n, p;
    int a, b, m, r;

    while (scanf("%d %d\n", &n, &p) == 2) {
        r = p + (p % 2 == 0? -1: 1);
        a = n - p + 1;
        b = n - r + 1;
        m = min(max(a, b), min(max(a, r), max(b, r))); // Middle element
        printf("%d %d %d\n", min(min(a, b), r), m, max(max(a, b), r));
    }

    return 0;
}

