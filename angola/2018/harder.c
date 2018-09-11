#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int a, b;

    scanf("%lld %lld\n", &a, &b);
    printf("%lld\n", 2ll * (a + b));

    return 0;
}

