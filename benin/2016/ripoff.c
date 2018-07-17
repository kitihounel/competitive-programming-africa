/**
 * TLE program.
 * An idea is to store for each cell the best rebate we can obtain with a certain number of remaining turn.
 * For cell j, we can get Y with X turns remaining. 
 * For cell j, we can get Z with T turns remaining. 
 */
#include <stdio.h>
#include <limits.h>

#define DEBUG 0
#define MAX_N 200

int N, S, T;
int board[MAX_N + 1];
int maxRebate;

int stack[MAX_N];
int stackLength;

void printStack()
{
#ifdef DEBUG
    for (int j = 0; j < stackLength; ++j) {
        printf("%3d", stack[j]);
    }
    printf(" => %d\n", maxRebate);
#endif
}

void check(int pos, int currentRebate, int remaining)
{
    if (pos > N) {
        if (currentRebate > maxRebate) {
            maxRebate = currentRebate;
            printStack();
        } else {
            return;
        }
    }

    if (remaining == 0) {
        return;
    }

    stack[stackLength++] = pos;
    for (int j = 1; j <= S; ++j) {
        check(pos + j, currentRebate + board[pos], remaining - 1);
    }
    --stackLength;
}

int main()
{
    scanf("%d\n", &N);
    while (N != 0) {
        scanf("%d %d\n", &S, &T);
        for (int j = 1; j <= N; ++j) {
            scanf("%d", board + j);
        }

        maxRebate = INT_MIN;
        for (int j = 1; j <= S; ++j) {
            check(j, 0, T - 1);
        }

        printf("%d\n", maxRebate);
        scanf("%d\n", &N);
    }

    return 0;
}

