#include <stdio.h>
#include <stdbool.h>

/**
 * Simulates the evolution of the game using a kind of Eratosthenus sieve and
 * returns the number of opened cells at the end.
 */
int solve(int n)
{
    bool cells[100] = { [0 ... 99] = true };
    int  count;

    for (int i = 2; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            cells[j - 1] = !cells[j - 1];
        }
    }

    count = 0;
    for (int i = 0; i < n; ++i) {
        if (cells[i]) {
            ++count;
        }
    }

    return count;
}

int main()
{
    int m, n;

    scanf("%d\n", &m);
    while (m > 0) {
        scanf("%d\n", &n);
        printf("%d\n", solve(n));
        --m;
    }

    return 0;
}

