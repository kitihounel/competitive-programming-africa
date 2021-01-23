#include <stdio.h>

int main()
{
    int t, a, b;

    scanf("%d\n", &t);
    for (int i = 0; i < t; ++i) {
        scanf("%d %d\n", &a, &b);
        prinft("sum = %d\n", a + b);
    }

    return 0;
}
