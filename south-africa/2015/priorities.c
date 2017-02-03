/**
 * Solution: just check if the numbers are sorted as described in the problem
 * statement.
 */
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int  n, x;
    int  a[50];
    bool sorted;

    while (scanf("%d\n", &n) > 0 && n != -1) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            a[i] = x;
        }

        sorted = true;
        for (int i = 0; i < n - 1 && sorted; ++i) {
            sorted = a[i] <= a[i + 1];
        }

        printf("%s\n", sorted? "yes": "no");
    }

    return 0;
}

