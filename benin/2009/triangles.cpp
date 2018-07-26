#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_ROW = 400;

int values[1600000], rowNumbers[160000], partialSums[160000];

int main()
{
    int k, n, r, bestTotal;

    for (int row = 0, t = 0; row < MAX_ROW; ++row) {
        int rowLength = 2 * row + 1;
        for (int j = 0; j < rowLength; ++j) {
            rowNumbers[t] = row;
            ++t;
        }
    }

    k = 1;
    while (scanf("%d", &r) == 1 && r != 0) {
        bestTotal = -1000;
        n = r * r;
        for (int j = 0, currentRow = -1, currentRowTotal = 0; j < n; ++j) {
            if (rowNumbers[j] != currentRow) {
                currentRow = rowNumbers[j];
                currentRowTotal = 0;
            }

            scanf("%d", values + j);
            currentRowTotal += values[j];
            partialSums[j] = currentRowTotal;
            bestTotal = max(bestTotal, values[j]);
        }

        for (int j = 0; j < n; ++j) {
            if (j % 2 != rowNumbers[j] % 2) {
                continue;
            }

            int total = values[j];
            int bottomLeft = j + 2 * rowNumbers[j] + 1;
            int bottomRight = bottomLeft + 2;
            while (bottomLeft < n) {
                total += partialSums[bottomRight] - partialSums[bottomLeft] + values[bottomLeft];
                bestTotal = max(bestTotal, total);
                bottomLeft += 2 * rowNumbers[bottomLeft] + 1;
                bottomRight += 2 * rowNumbers[bottomRight] + 3;
            }
        }

        for (int j = n - 1; j > 0; --j) {
            if (j % 2 == rowNumbers[j] % 2) {
                continue;
            }

            int top = j - 2 * rowNumbers[j];
            int topLeft = top - 1;
            int topRight = top + 1;
            int total = values[j];
            while (topLeft > 0 && topRight > 0 && rowNumbers[topLeft] == rowNumbers[topRight]) {
                total += partialSums[topRight] - partialSums[topLeft] + values[topLeft];
                bestTotal = max(bestTotal, total);
                topLeft = topLeft - 2 * rowNumbers[topLeft] - 1;
                topRight = topRight - 2 * rowNumbers[topRight] + 1;
            }
        }

        printf("%d. %d\n", k, bestTotal);
        ++k;
    }

    return 0;
}

