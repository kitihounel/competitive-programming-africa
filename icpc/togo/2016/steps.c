#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c, d, l, w;
    int p;
    
    scanf("%d\n", &p);
    while (p > 0) {
        scanf("%d %d %d %d %d %d\n", &l, &w, &a, &b, &c, &d);
        printf("%d\n", abs(a - c) + abs(b - d));
        --p;
    }
    
    return 0;
}

