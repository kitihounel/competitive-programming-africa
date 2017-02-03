/**
 * The solution is to use depth-first search and to discover all the cells that
 * are reachable from the start position. At tha end of the search, we check
 * if the destination has been discovered in the search.
 * On the grid shown on the problem statement, rows are numbered from bottom to
 * top, which is not the way that arrays are numbered in C. So we make a little
 * change on row coordinates and number them from top to bottom.
 *
 * Note: the solution was given by the organiser of the contest. I won't cite
 * his name here, but if you are curious enough, you will easily find who I'm
 * talking about.
 */
#include <stdio.h>
#include <stdbool.h>

/* This structure is used to hold the coordinates of the cells. */
typedef struct cell {
    int x, y;
} CELL;

/* Determine if a cell at the coordinates hold by p really lies on the map. */
bool isValid(CELL c, int w, int l)
{
    return (c.x >= 0 && c.x < w) && (c.y >= 0 && c.y < l);
}

/* Function that use death-first search to discover all cells that are */
/* from an entry cell. */
bool visit(CELL c, int w, int l, char grid[][l], bool visited[][l])
{
    /* Neighbors of the current cell. */
    CELL neighbors[] = {
        { c.x, c.y - 1 }, { c.x, c.y + 1}, { c.x + 1, c.y }, {c.x - 1, c.y}
    };

    visited[c.x][c.y] = true;
    for (int i = 0; i < 4; ++i) {
        int x = neighbors[i].x;
        int y = neighbors[i].y;
        if ( isValid(neighbors[i], w, l) && grid[c.x][c.y] == grid[x][y]
                    && !visited[x][y] ) {
            visit(neighbors[i], w, l, grid, visited);
        }
    }
}

int main()
{
    int p;
    int l, w;
    CELL src, dst;

    scanf("%d\n", &p);
    while (p > 0) {
        scanf("%d %d %d %d %d %d\n", &l, &w, &src.y, &src.x, &dst.y, &dst.x);

        char grid[w][l];
        bool visited[w][l];
        for (int i = 0; i < w; ++i) {
            for (int j = 0; j < l; ++j) {
                grid[i][j] = getc(stdin);
                visited[i][j] = false;
            }
            getc(stdin);
        }

        /* Transformation of the row coordinates of the cells. */
        src.x = w - src.x; --src.y;
        dst.x = w - dst.x; --dst.y;

        if (grid[src.x][src.y] == grid[dst.x][dst.y]) {
            visit(src, w, l, grid, visited);
            printf("%s\n", visited[dst.x][dst.y]? "YES": "NO");
        } else {
            printf("NO\n");
        }

        --p;
    }

    return 0;
}
