/**
 * Dynamic programming problem.
 *
 *
 * Description of the algorithm.
 *  let total be a (N+1) * (T+1) array
 *      total[j][t] is the max rebate we can get if we are on square j with t turns left
 *
 *  let rebate be an array with N elements
 *      rebate[j] is the rebate which is offered by square j
 *
 *  for each square j from the end to the start (j = N to 0, square 0 is the starting position):
 *      for each turn t in [1, T]:
 *          for each square k which is after j:
 *              if we jump to k from j and we can finish the game in t-1 turns from k:
 *                  totalRebate[j][t] = max(totalRebate[j][t], totalRebate[k][t-1] + rebate[j])
 *
 * The maximum rebate a customer can win is then total[N][T]
 *
 * Time complexity
 *  - The initilization of the 'total' array needs N*T operations.
 *  - We run 3 loops to get our result: N*T*N.
 *  - Total: N*T + N²T => O(N²T).
 *  - Given the size of N and T, this is not so bad :).
 */
#include <stdio.h>
#include <limits.h>

#define MAX_N      200
#define MAX_T      201
#define INF   10000000

int N, S, T;
int board[MAX_N+1], distance[MAX_N+1], dp[MAX_N+1][MAX_T+1];

int max(int a, int b)
{
    return (a > b ? a : b);
}

int min(int a, int b)
{
    return (a < b ? a : b);
}

int main()
{
    while (scanf("%d %d %d\n", &N, &S, &T) == 3) {

        // We need to compute for each square, the number of turns needes
        // to reach the end from it.
        distance[0] = (N + 1) / S + min((N + 1) % S, 1);
        for (int j = 1; j <= N; ++j) {
            scanf("%d", board + j);
            distance[j] = (N + 1 - j) / S + min((N + 1 - j) % S, 1);
        }

        // Initialization of the values of the DP array.
        for (int square = 0; square <= N; ++square) {
            for (int turnsLeft = 0; turnsLeft <= T; ++turnsLeft) {
                if (turnsLeft == 0) {
                    // If we have no turn left, we can't get anything.
                    dp[square][turnsLeft] = -INF;
                } else if (distance[square] <= 1) {
                    // We can reach end from current square.
                    dp[square][turnsLeft] = board[square];
                } else {
                    dp[square][turnsLeft] = -INF;
                }
            }
        }

        for (int currentSquare = N - 1; currentSquare >= 0; --currentSquare) {
            for (int turnsLeft = 1; turnsLeft <= T; ++turnsLeft) {
                for (int square = currentSquare + 1; square <= N; ++square) {
                    if ((square <= currentSquare + S) && (distance[square] <= turnsLeft - 1)) {
                        dp[currentSquare][turnsLeft] = max(
                            dp[currentSquare][turnsLeft],
                            dp[square][turnsLeft-1] + board[currentSquare]
                        );
                    }
                }
            }
        }

        printf("%d\n", dp[0][T]);
    }

    return 0;
}

