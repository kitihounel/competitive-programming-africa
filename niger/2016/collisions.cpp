/**
 * This solution is provided in C++ because it is very easy to solve the
 * problem using STL map.
 * We will store the number of queens on a row, column, or diagonal in maps.
 * The keys of the maps are the row, col and diagonal numbers, values are
 * the number of queens.
 *
 * Getting the row and the column of a cell on a chessboard is easy. They
 * are given by the coordinates of the cell. Getting diagonals is also easy.
 * A cell belongs to two diagonals. We will call them ascending diagonal and
 * descending diagonal. The ascending diagonal of a cell (x, y) is given by
 * x + y while the descending diagonal is given by x - y. If you didn't know
 * this cool thing, take a paper and a pencil and draw two chessboards of same
 * size. In each cell (x, y) of the first chessboard, put the value x + y and
 * in each cell of the second one, put the value x - y.
 * You will see the pattern.
 *
 * Now we can read the input data and compute the positions of the queens. When
 * we get a queen, we increase the count of its row, column and diagonals.
 * Then we can compute the number of collisions on a row which is the number of
 * queens on the row minus one. The same holds for columns and diagonals.
 */
#include <iostream>
#include <cstdio>
#include <unordered_map>

using namespace std;

int main()
{
    int g, k, n, s, t, x, y;
    int r, c;
    int count;
    unordered_map<int, int> rows, cols, ascd, desc;

    while (scanf("%d %d\n", &n, &g) == 2) {
        while (g > 0) {
            scanf("%d %d %d %d %d\n", &k, &x, &y, &s, &t);
            for (int i = 0; i < k; ++i) {
                r = x + i * s;
                c = y + i * t;

                ++rows[r];
                ++cols[c];
                ++ascd[r + c];
                ++desc[r - c];
            }
            --g;
        }

        count = 0;
        for (const auto &p: rows) count += p.second - 1;
        for (const auto &p: cols) count += p.second - 1;
        for (const auto &p: desc) count += p.second - 1;
        for (const auto &p: ascd) count += p.second - 1;

        printf("%d\n", count);

        rows.clear();
        cols.clear();
        desc.clear();
        ascd.clear();
    }

    return 0;
}
