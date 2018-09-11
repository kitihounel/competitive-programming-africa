#include <stdio.h>

#define MAX_N 10000

int terms[MAX_N+1];

int main()
{
    int n, t;

    terms[1] = terms[2] = 1;
    for (int j = 3; j <= MAX_N; ++j) {
        terms[j] = (terms[j-1] + terms[j-2]) % 10000;
    }

    scanf("%d\n", &t);
    while (t > 0) {
        scanf("%d\n", &n);
        printf("%d %d %d\n", terms[n-2], terms[n-1], terms[n]);
        --t;
    }

    return 0;
}

