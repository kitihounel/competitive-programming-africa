#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    long long int a, b, c, r, s, t;
    long long int x, y, z;
    int  p;

    scanf("%d\n", &p);
    for (int i = 0; i < p; ++i) {
        scanf("%lldx + %lldy = %lld\n", &a, &b, &c);
        scanf("%lldx + %lldy = %lld\n", &r, &s, &t);
        x = (c * s) - (b * t);
        y = (a * t) - (r * c);
        z = (a * s) - (b * r);

        printf("%sEquation %d\n", (i > 0? "\n": ""), i + 1);
        if (z == 0) {
            if (x == 0ll && y == 0ll) {
                printf("More than one solution.\n");
            } else {
                printf("No solution.\n");
            }
        } else {
            printf("x = %lld.%06lld  y = %lld.%06lld\n",
                    x / z, (llabs(x) % llabs(z)) * 1000000 / llabs(z),
                    y / z, (llabs(y) % llabs(z)) * 1000000 / llabs(z));
        }
    }

    return 0;
}

