#include <stdio.h>

int main()
{
    int n, m, root;
    
    while (scanf("%d\n", &n) > 0 && n != 0) {
        m = n % 9;
        root = (m == 0? 9 : m); // WTF?!
        printf("%d\n", root);
    }

    return 0;
}

