#include <stdio.h>
#include <stdbool.h>

typedef int triangle[3];

const int N = 6;

int max(int a, int b)
{
    return a > b? a: b;
}

void swap(int a[], int b[], int length)
{
    int tmp;
    
    for (int i = 0; i < length; ++i) {
        tmp  = a[i]; 
        a[i] = b[i];
        b[i] = tmp;
    }
}

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

bool match(triangle a, triangle b)
{
    return a[2] == b[0];
}

int getScore(triangle board[N])
{
    int score = 0;

    for (int i = 0; i < N; ++i) {
        score += board[i][1];
    }

    return score;
}

int fit(triangle board[], int i)
{
    int score = 0;

    if (i == N) {
        if (match(board[N - 1], board[0])) {
            return getScore(board);
        }
    } else {
        for (int j = i; j < N; ++j) {
            swap(board[i], board[j], 3);
            for (int k = 0; k < 3; ++k) {
                if (match(board[i - 1], board[i])) {
                    score = max(score, fit(board, i + 1));
                }
                rotate(board[i], 3);
            }
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

