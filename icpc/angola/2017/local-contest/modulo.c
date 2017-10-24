#include <stdio.h>

int main()
{
    int a[42] = { 0 };
    int ans, n, r;

    ans = 0;
    for (int i = 0; i < 10; ++i) {
        scanf("%d\n", &n);
        r = n % 42;
        if (a[r] == 0) {
          ++ans;
        }
        a[r] = 1;
    }
    printf("%d\n", ans);

    return 0;
}
