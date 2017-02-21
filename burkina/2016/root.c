#include <stdio.h>

int main()
{
    int n, m;
    
    while (scanf("%d\n", &n) > 0 && n != 0) {
        m = n % 9;
        printf("%d\n", m == 0 ? 9: m);
    }

    return 0;
}

