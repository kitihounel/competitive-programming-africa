#include <stdio.h>
#include <stdbool.h>

#define N 40000

int lucky[N + 1];
int numbers[N + 1];
int count;

void sieve()
{
    for (int i = 0; i <= N; ++i) numbers[i] = true;
    for (int i = 2; i <= N; ++i) {
        if (!numbers[i]) continue;
        lucky[count++] = i;
        int j = i + 1;
        while (j <= N) {
            int c = (numbers[j] ? 1 : 0);
            while (j <= N && c < i) {
                j += 1;
                c += (j <= N && numbers[j] ? 1 : 0);
            }
            if (j <= N) numbers[j] = false;
            j += 1;
        }
    }
}

int main()
{
    int n;
    
    sieve();
    while (scanf("%d\n", &n) && n != 0) {
        printf("%d\n", lucky[n - 1]);
    }

    return 0;
}

