#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Search for the word "TOGO" in the rows `matrix`.
 */
bool find(int n, int l, char matrix[][l])
{
    bool found = false;

    for (int i = 0; i < n && !found; ++i) {
        found = (strstr(matrix[i], "TOGO") != NULL);
    }

    return found;
}

int main()
{
    int  n, p;
    bool found;
    char matrix[1000][1001];
    char transpose[1000][1001];

    scanf("%d\n", &p);
    while (p > 0) {
        scanf("%d\n", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%s\n", matrix[i]);

            /* Build the jth line of the transpose. */
            for (int j = 0; j < n; ++j) {
                transpose[j][i] = matrix[i][j];
            }
            transpose[i][n] = '\0';
        }

        found = find(n, 1001, matrix) || find(n, 1001, transpose);
        printf("%sTROUVE\n", found? "": "NON ");
        --p;
    }

    return 0;
}

