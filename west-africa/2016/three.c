/**
 * We will use Erasthostenus sieve to generate all prime numbers up to 1000000.
 * Then we will check each number in the input. If the number is prime and its
 * last digit is 3, we answer yes. If the number is not prime, we will get all
 * its prime factors and check if all of them has 3 as last digit.
 *
 * There are approximately X = N / ln(N) prime numbers below any number N.
 * You can get an upper bound by multiplying by 1.2.
 * So, 1000000 / ln(1000000) * 1.2 = 86858.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 1000000

bool numbers[N + 1] = { [0 ... 1] = false, [2 ... 1000000] = true };
int  primes[86858];

void sieve()
{
    for (int i = 2; i <= 1000; ++i) {
        if (!numbers[i]) continue;
        for (int j = i + i; j <= N; j += i) numbers[j] = false;
    }
    for (int i = 2, j = 0; i <= 1000000; ++i) {
        if (numbers[i]) primes[j++] = i;
    }
}

int main()
{
    int  n, i, tmp;
    bool ok;

    sieve();
    while (scanf("%d\n", &n) != 0 && n != -1) {
        if (numbers[n]) {
            // N is a prime number.
            printf("%d %s\n", n, (n % 10 == 3 ? "YES" : "NO"));
            continue;
        }
        // N is not prime. We search its prime factors and check if all of them
        // has 3 as last digit.
        tmp = n;
        i   = 0;
        ok  = true;
        while (primes[i] * primes[i] <= tmp && ok) {
            if (tmp % primes[i] == 0) {
                ok = primes[i] % 10 == 3;
            }
            if (!ok) break;
            while (tmp % primes[i] == 0) {
                tmp /= primes[i];
            }
            ++i;
        }
        if (tmp != 1 && ok) {
            ok = tmp % 10 == 3;
        }
        printf("%d %s\n", n, (ok ? "YES": "NO"));
    }

    return 0;
}
