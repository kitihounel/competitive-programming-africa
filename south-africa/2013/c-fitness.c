#include <stdio.h>

int main()
{
    int a, b, d, m;

    while (scanf("%d %d %d\n", &a, &b, &m) == 3) {
        d = a - b;
        while (d % m != 0) {
          --m;
        }
        printf("%d\n", m);
    }

    return 0;
}

