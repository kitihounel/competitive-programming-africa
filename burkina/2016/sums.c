#include <stdio.h>

int main()
{
    int k, n, p;

    scanf("%d\n", &p);
    while (p > 0) {
        scanf("%d %d\n", &k, &n);
        printf("%d %d %d %d\n", k, n * (n + 1) / 2, n * n, n * (n + 1));
        --p;
    }

    return 0;
}

