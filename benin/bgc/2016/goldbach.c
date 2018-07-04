#include <stdio.h>
#include <stdbool.h>

#define N 1000000
#define M 1000
#define P 86858

bool numbers[N + 1] = { [0 ... 1] = false, [2 ... N] = true };
int  primes[86858];
int  primeCount;

void sieve()
{
    for (int i = 2; i <= M; i++) {
        if (numbers[i] == false) continue;
        for (int j = i + i; j <= N; j += i) numbers[j] = false;
    }
    primes[primeCount++] = 2;
    for (int i = 3; i <= N; i += 2) {
        if (numbers[i] == true) primes[primeCount++] = i;
    }
}

int main()
{
    bool b;
    int  n, sum;

    sieve();
    while (scanf("%d\n", &n) > 0 && n != 0) {
        int  i = 0;
        int  j = primeCount - 1;
        bool b = false;
        while (j >= i && !b) {
            int sum = primes[i] + primes[j];
            if (sum == n) {
                b = true;
            } else {
                if(sum > n) {
                    j--;
                } else {
                    i++;
                }
            }
        }

        if (b) {
            printf("%d = %d + %d\n", n, primes[i], primes[j]);
        } else {
            printf("Goldbach's conjecture is wrong.\n");
        }
    }

    return 0;
}
