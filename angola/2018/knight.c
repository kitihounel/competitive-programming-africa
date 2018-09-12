/**
 * We model the board as a graph and cell as vertices.
 * There is an edge between two vertices U and V if we can reach V from U
 * by using a knight move. Knight move looks like a 'L' (Read more on Wikipedia).
 * After that, we use FLOYD-WARSHALL algorithm to compute the shortest paths between
 * all pairs of vertices. And then we can answer to the questions. :)
 * 
 * Note: you will need gcc to compile this program. Line 16, designated initis.
 */
#include <stdio.h>
#include <limits.h>

#define BOARD_SIZE  8
#define CELL_COUNT 64

int distances[CELL_COUNT][CELL_COUNT] = { [0 ... CELL_COUNT-1][0 ... CELL_COUNT-1] = INT_MAX };

int dx[] = { +2, +2, -2, -2, +1, +1, -1, -1 };
int dy[] = { -1, +1, -1, +1, -2, +2, -2, +2 };

int toIndex(int x, int y)
{
    return x * BOARD_SIZE + y;
}

int getIndex(char r, char c)
{
    return (r - '1') * BOARD_SIZE + (c - 'a');
}

int min(int a, int b)
{
    return a < b? a: b;
}

int main()
{
    int    x, y;
    int  p1, p2;
    char c1, r1, c2, r2;

    // Adjacency matrix construction.
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            int p = toIndex(i, j);

            distances[p][p] = 0;
            for (int k = 0; k < 8; ++k) {
                x = i + dx[k];
                y = j + dy[k];
                if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE)
                    distances[p][toIndex(x, y)] = 1;
            }
        }
    }

    // FLOYD-WARSHALL algorithm.
    for (int k = 0; k < CELL_COUNT; ++k) {
        for (int i = 0; i < CELL_COUNT; ++i) {
            for (int j = 0; j < CELL_COUNT; ++j) {
                if (distances[i][k] != INT_MAX && distances[k][j] != INT_MAX)
                    distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
            }
        }
    }

    scanf("%c%c %c%c\n", &c1, &r1, &c2, &r2);
    while (c1 != '#') {
        p1 = getIndex(r1, c1);
        p2 = getIndex(r2, c2);
        printf("To get from %c%c to %c%c takes %d knight moves.\n", c1, r1, c2, r2, distances[p1][p2]);
        scanf("%c%c %c%c\n", &c1, &r1, &c2, &r2);
    }

    return 0;
}

