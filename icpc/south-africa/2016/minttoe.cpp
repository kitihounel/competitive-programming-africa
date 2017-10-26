/**
 * This problem can be solved using backtracking.
 * This code give corrects answers to the problem, but it needs to be
 * improved.
 *
 * Explaination of the logic.
 * Given the initial state of the board, we test all possible plays for the X
 * player. If for a play, there is no possibility for O to win, we increment
 * the count of good moves.
 *
 * Note: we let the debug output so that we can follow the evolution of the
 * game.
 */
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char board[3][3];
int  happyEndingCount, freeCellCount;

/**
 * Check if all marks on the ith row of the board are the same and not dots.
 */
bool checkRow(int i)
{
    return board[i][0] != '.' && board[i][0] == board[i][1]
        && board[i][0] == board[i][2];
}

/**
 * Check if all marks on the ith column of the board are the same and not dots.
 */
bool checkCol(int j)
{
    return board[0][j] != '.' && board[0][j] == board[1][j]
        && board[0][j] == board[2][j];
}

/**
 * Check the first diagonal, the one that contains cell(2, 0).
 */
bool checkFirstDiagonal()
{
    return board[2][0] != '.' && board[2][0] == board[1][1]
        && board[2][0] == board[0][2];
}

/**
 * Check the second diagonal, the one that contains cell(0, 0).
 */
bool checkSecondDiagonal()
{
    return board[0][0] != '.' && board[0][0] == board[1][1]
        && board[0][0] == board[2][2];
}

/**
 * Return true if the cell(i, j) lies on a diagonal and all marks on the
 * diagonal are the same. Note that for cell(1, 1), we have to check both
 * diagonals.
 */
bool checkDiagonals(int x, int y)
{
    bool b;

    if (x == 1 && y == 1)
         b = checkFirstDiagonal() || checkSecondDiagonal();
    else if (x + y == 2)
        b = checkFirstDiagonal();
    else if (x - y == 0)
        b = checkSecondDiagonal();
    else
        b = false;

    return b;
}

/**
 * If player is even, it is the X player turn. Else it is O player turn.
 */
void solve(int player)
{
    // fprintf(stderr, "player %d\n", player);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {

            if (board[i][j] != '.')
                continue;

            // We mark the cell and decrease the number of free cells.
            // We then check if current move makes the player win or a draw.
            board[i][j] = (player % 2 == 0 ? 'X' : 'O');
            --freeCellCount;

            if (checkRow(i) || checkCol(j) || checkDiagonals(i, j)) {
                // Winning move. We stop recursion here. If the current player
                // is X, that is favourable to us.
                // fprintf(stderr, "final position found\n");
                // for (int i = 0; i < 3; ++i) {
                //    for (int j = 0; j < 3; ++j)
                //        fprintf(stderr, "%c", board[i][j]);
                //    fprintf(stderr, "\n");
                // }
                if (player % 2 == 1)
                    ++happyEndingCount;
            } else if (freeCellCount > 0) {
                solve(player + 1);
            } else {
                // Game end without a winner. That is favourable to us.
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
    int  answer;

    while (scanf("%s\n", line) > 0 && line[0] !=  '-') {
        freeCellCount = 0;
        // We read the first row of the board. 
        for (int j = 0; j < 3; ++j) {
            board[0][j] = line[j];
            if (line[j] == '.')
                ++freeCellCount;
        }
        // Now we read the two remaining rows.
        for (int i = 1; i < 3; ++i) {
            scanf("%s\n", line);
            for (int j = 0; j < 3; ++j) {
                board[i][j] = line[j];
                if (line[j] == '.')
                    ++freeCellCount;
            }
        }
        scanf("\n");

        // For each of the available moves for the X player, we check if all
        // the possibilities left to the O player lead to a good ending for X.
        // If any of the left possibilities enable O to win, we know that O
        // will choose it.
        answer = 0;
        if (freeCellCount == 1) {
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (board[i][j] != '.') continue;
                    board[i][j] = 'X';
                    answer = checkRow(i) || checkCol(j) || checkDiagonals(i, j);
                    break;
                }
            }
        } else {
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (board[i][j] != '.') continue;
                    // fprintf(stderr, "putting X at %d %d\n", i, j);
                    board[i][j] = 'X';
                    --freeCellCount;
                    happyEndingCount = 0;
                    solve(1);
                    // fprintf(stderr, "happy endings %d\n", happyEndingCount);
                    if (happyEndingCount == 0) {
                        ++answer;
                        // fprintf(stderr, "happy ending\n");
                    } else {
                        // fprintf(stderr, "no happy ending %d\n", happyEndingCount);
                    }
                    ++freeCellCount;
                    board[i][j] = '.';
                }
            }
        }

        printf("%d\n", answer);
    }

    return 0;
}

