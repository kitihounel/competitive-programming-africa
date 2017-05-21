/**
 * This problem is a little about geometry and translation.
 * Each number moves from position (i, j) to position (n - 1 - i, n - 1 - j).
 * A square is beautiful if for each cell, the following equality holds:
 *           square[i][j] = square[n - 1 - i][n - 1 - j]
 *
 * Tip: We do not need to check the above equality for all the cells in the
 *      square. We can do the check for the cells between positions (0, 0) and
 *      (n / 2 - 1, n / 2 - 1)
 */
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int  l, n, p;
    int  a[30][30];
    bool beautiful;
    
    scanf("%d\n", &p);
    while (p > 0) {
        scanf("%d\n", &n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &a[i][j]);
            }
        }
        
        l = n / 2;
        beautiful = true;
        for (int i = 0; i < l && beautiful; ++i) {
            for (int j = 0; j < l && beautiful; ++j) {
                beautiful = ( a[i][j] == a[n - 1 - i][n - 1 - j] );
            }
        }
        
        printf("%sbeautiful square\n", beautiful? "": "not a ");

        --p;
    }
    
    return 0;
}

