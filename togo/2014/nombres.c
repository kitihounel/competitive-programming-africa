#include <stdio.h>

int main()
{
    int p;
    int a, b;

    scanf("%d\n", &p);
    while (p > 0) {
        scanf("%d %d\n", &a, &b);
        printf("%d %d %d\n", a, b, (a - b) / 2);
        --p;
    }

    return 0;
}

