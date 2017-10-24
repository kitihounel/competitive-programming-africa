#include <stdio.h>

int main()
{
    int n;

    while (scanf("%d\n", &n) > 0) {
        printf("%d\n", n == 1 ? 1 : 2 * n - 2);
    }

    return 0;
}

