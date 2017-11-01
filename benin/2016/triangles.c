/**
 * This solution is heavily based on the official solution which can be found
 * in the file Triangle.java. We just rewrite it in C without global vars.
 * But there a few changes.
 *  - This solution is more generic and can work with boards of different size,
 *    i.e. we are no more limited to 6 triangles.
 *  - Triangles are still represented by array of 3 elements but the value used
 *    to compute score is always the middle element, i.e. element at index 1.
 *  - We rotate triangle by doing a right shift, so that element at index 0
 *  - moves to index 1, element at index 1 moves to index 2 and element at index
 *    2 moves to index 0.
 *  - Two consecutive triangles t and u match if t[2] = u[0].
 *
 * The program uses backtracking and tries to find all valid combinations of
 * triangles. Each time a valid combo is found, its score is computed and
 * if the score is best than the previous one we keep it.
 */
#include <stdio.h>
#include <stdbool.h>

typedef int triangle[3];

/* Number of triangles we play with. */
const int N = 6;

/**
 * Returns the maximum of two numbers.
 * We use this function to compute successive score and keep the best one.
 */
int max(int a, int b)
{
    return a > b? a: b;
}

/**
 * Swaps the content of two arrays.
 */
void swap(int a[], int b[], int length)
{
    int tmp;
    
    for (int i = 0; i < length; ++i) {
        tmp  = a[i]; 
        a[i] = b[i];
        b[i] = tmp;
    }
}

/**
 * Rotates an array.
 * The last element becomes the first one.
 */
void rotate(int a[], int length)
{
    int tmp, val;

    val = a[length - 1];
    for (int i = 0; i < length; ++i) {
        tmp  = a[i];
        a[i] = val;
        val  = tmp;
    }
}

/**
 * Checks if two triangles match, i.e. the adjacent edges have the same number.
 */
bool match(triangle a, triangle b)
{
    return a[2] == b[0];
}

/**
 * Computes the score of a board.
 */
int getScore(triangle board[N])
{
    int score = 0;

    for (int i = 0; i < N; ++i) {
        score += board[i][1];
    }

    return score;
}

/**
 * Triangles before the ith fit together, try with the remaining ones.
 * If i = N, just check match of the last triangle with the first, since the
 * board is circular.
 * If a valid combo is found, returns the score of the combination. Otherwise,
 * returns 0.
 */
int fit(triangle board[], int i)
{
    int score = 0;

    if (i == N) {
        // No more triangles. Check if the last and the first match and returns
        // the score.
        if (match(board[N - 1], board[0])) {
            return getScore(board);
        }
    } else {
        // We try to find a triangle that matches with the previous one.
        // Since we are using backtracking, we try all the remaining triangles.
        for (int j = i; j < N; ++j) {
            swap(board[i], board[j], 3);
            for (int k = 0; k < 3; ++k) {
                if (match(board[i - 1], board[i])) {
                    // We found a new match. We continue to search with the
                    // remaining triangles.
                    score = max(score, fit(board, i + 1));
                }
                rotate(board[i], 3);
            }
            // Remember we are using backtracking. We undo the swap.
            swap(board[i], board[j], 3);
        }
    }
    
    return score;
}

int main()
{
    triangle hex[N];
    int  score;
    char ch;

    while (true) {
        for (int i = 0; i < N; ++i) {
            scanf("%d %d %d\n", &hex[i][0], &hex[i][1], &hex[i][2]);
        }
        scanf("%c\n", &ch);

        score = 0;
        for (int i = 0; i < 3; ++i) {
            score = (max(score, fit(hex, 1)));
            rotate(hex[0], 3);
        }
        
        if (score == 0) {
            printf("%s\n", "none");
        } else {
            printf("%d\n",  score);
        }

        if (ch == '$') {
            break;
        }
    }
    
    return 0;
}

