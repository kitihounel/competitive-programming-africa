/**
 * The parity property can be established if there are exactly one row and
 * one column with an odd sum.
 */ 
#include <stdio.h>

int main()
{
    int matrix[100][100];
    int n;
    int badCol, badRow;
    int badRowCount, badColCount;

    while (scanf("%d", &n) > 0 && n != 0) {
        badRowCount = badColCount = 0;

        // We read input and check rows.
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                scanf("%d", &matrix[i][j]);
                sum += matrix[i][j];
            }
            if (sum % 2 == 1) {
                badRow = i + 1;
                ++badRowCount;
            }
        }

        // Now we check the columns.
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += matrix[i][j];
            }
            if (sum % 2 == 1) {
                badCol = j + 1;
                ++badColCount;
            }
        }

        if (badColCount == 0 && badRowCount == 0) {
            printf("OK\n");
        } else {
            if (badColCount == 1 && badRowCount == 1) {
                printf("Change bit (%d,%d)\n", badRow, badCol);
            } else {
                printf("Corrupt\n");
            }
        }
    }

    return 0;
}
