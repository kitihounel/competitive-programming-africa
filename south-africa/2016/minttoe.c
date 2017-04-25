/**
 * This problem can be solved using backtracking.
 * This code does give correct answers to the problem. It needs to be improved.
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char board[3][3];
int  answer, freeCellCount;

/**
 * Check if all marks on the ith row of the board are the same and not dots.
 */
bool checkRow(int i)
{
    return board[i][0] != '.'
           && board[i][0] == board[i][1] && board[i][0] == board[i][2];
}

/**
 * Check if all marks on the ith column of the board are the same and not dots.
 */
bool checkCol(int j)
{
    return board[0][j] != '.'
           && board[0][j] == board[1][j] && board[0][j] == board[2][j];
}

/**
 * Check the first diagonal, the one that contains cell(2, 0).
 */
bool checkFirstDiagonal()
{
    return board[2][0] != '.'
           && board[2][0] == board[1][1] && board[2][0] == board[0][2];
}

/**
 * Check the second diagonal, the one that contains cell(0, 0).
 */
bool checkSecondDiagonal()
{
    return board[0][0] != '.'
           && board[0][0] == board[1][1] && board[0][0] == board[2][2];
}

/**
 * Return true if the cell(i, j) lies on a diagonal and all marks on the
 * diagonal are the same. Note that for cell(1, 1), we have to check both
 * diagonals.
 */
bool checkDiagonals(int x, int y)
{
    bool b;

    if (x == 1 && y == 1) {
         b = checkFirstDiagonal() || checkSecondDiagonal();
    } else if (x + y == 2) {
        b = checkFirstDiagonal();
    } else if (x - y == 0) {
        b = checkSecondDiagonal();
    } else {
        b = false;
    }

    return b;
}

/**
 * If player is even, it is the X player turn. Else it is O player turn.
 */
void solve(int player)
{
    fprintf(stderr, "player %d\n", player);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != '.') continue;
            // We mark the cell and decrease the number of free cells.
            // We then check if current move makes the player win or a draw.
            board[i][j] = player % 2 == 0 ? 'O' : 'X';
            --freeCellCount;
            if (checkRow(i) || checkCol(j) || checkDiagonals(i, j)) {
                // Winning move. We stop recursion here. If the current player
                // is X, that is favourable to us.
                if (player % 2 == 0) ++answer;
            } else {
                if (freeCellCount > 0) {
                    solve(player + 1);
                } else {
                    // Game end without a winner. That is favourable to us.
                    ++answer;
                }
            }
            // As we are using backtracking, we have to undo our current move.
            board[i][j] = '.';
            ++freeCellCount;
        }
    }
}

int main()
{
    char line[4];

    fprintf(stderr, "before shit\n");
    while (scanf("%s\n", line) > 0 && line[0] !=  '-') {
        freeCellCount = answer = 0;
        // We read the first row of the board. 
        for (int j = 0; j < 3; ++j) {
            board[0][j] = line[j];
            if (line[j] == '.') ++freeCellCount;
        }
        // Now we read the two remaining rows.
        for (int i = 1; i < 3; ++i) {
            scanf("%s\n", line);
            for (int j = 0; j < 3; ++j) {
                board[i][j] = line[j];
                if (line[j] == '.') ++freeCellCount;
            }
        }
        scanf("\n");
        fprintf(stderr, "dataset read\n");

        solve(0);
        printf("%d\n", freeCellCount);
    }

    return 0;
}

