#include <stdio.h>

int main()
{
    int  n;
    int  time[3];
    char horizontal[19] = { 0 }; // 3 rows and 6 columns + 1 cell for '\0'
    char vertical[19]   = { 0 }; // 6 rows ans 3 columns + 1 cell for '\0'

    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d:%d:%d\n", time, time + 1, time + 2);

        // We get the horizontal format.
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 6; ++k) {
                horizontal[6 * j + 5 - k] = (time[j] & (1 << k) ? '1': '0');
                // horizontal[j][k] = (time[j] & (1 << k) ? '1': 0);
            }
        }

        // The vertical format is just the transpose of the horizontal format.
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 6; ++k) {
                vertical[3 * k + 2 - j] = horizontal[6 * j + 5 - k];
                // vertical[k][j] = horizontal[j][k];
            }
        }

        // Result printing.
        printf("%d %s %s\n", i + 1, vertical, horizontal);
    }
}
