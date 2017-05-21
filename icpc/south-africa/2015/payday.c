/**
 * There is a small trap in this problem. Each salary should be processed 
 * independantly of others.
 * It seems that capitalism has conquered the galaxy...
 */
#include <stdio.h>

int main()
{
    const int denominations[] = { 30030, 2310, 210, 30, 6, 2, 1 };
    int m, salary, t;
    int quantities[ 7 ];

    t = 0;
    while (scanf("%d\n", &m) > 0 && m != -1) {
        // Set quantities to zero before processing each test case.
        for (int i = 0; i < 7; ++i) {
            quantities[i] = 0;
        }

        for (int i = 0; i < m; ++i) {
            scanf("%d", &salary);
            for (int j = 0; j < 7; ++j) {
                quantities[j] += salary / denominations[j];
                salary %= denominations[j];
            }
        }

        // Empty line between test cases.
        if(t != 0) {
            printf("\n");
        }
        
        for (int i = 0; i < 7; ++i) {
            printf("%d = %d\n", denominations[i], quantities[i]);
        }

        ++t;
    }

    return 0;
}

