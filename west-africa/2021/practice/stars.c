#include <stdio.h>

int isLeapYear(int y)
{
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

int main()
{
    int t, a, b;
    int n, x, y;

    scanf("%d\n", &t);
    for (int i = 0; i < t; ++i) {
        scanf("%d %d\n", &a, &b);
        x = (a / 400) + (a / 4) - (a / 100);
        y = (b / 400) + (b / 4) - (b / 100);
        n = y - x + (isLeapYear(a) ? 1 : 0);
        prinft("%d\n", n);
    }

    return 0;
}
