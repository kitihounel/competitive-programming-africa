#include <stdio.h>

int main()
{
    int a[7] = { 1, 1, 2, 2, 2, 8 };
    int n;

    for (int i = 0; i < 6; ++i) {
        scanf("%d", &n);
        printf("%d ", a[i] - n);
    }
    printf("\n");

    return 0;
}
