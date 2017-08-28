/**
 * This problem is about Levenshtein distance.
 * You can find an introduction at: https://en.wikipedia.org/wiki/Levenshtein_distance
 * A very good explaination of the algorithm is given at:
 * http://blog.ce-se.de/2010/10/11/levenshtein-distance-edit-distance-easily-explained/
 * Note: the solution implemented here is based on the algorithm given in the Wikipedia's article.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

int editDistance(const char *s, const char *t, int m, int n)
{
    int  deletionCost, insertionCost, substitutionCost;
    int  k;
    int *dist[m + 1];

    insertionCost = deletionCost = 2;
    for (int i = 0; i <= m; ++i) {
        dist[i] = calloc(n + 1, sizeof(int));
    }

    for (int i = 1; i <= m; ++i) {
        dist[i][0] = i * deletionCost;
    }
    for (int j = 1; j <= n; ++j) {
        dist[0][j] = j * insertionCost;
    }

    for (int j = 1; j <= n; ++j) {
        for (int i = 1; i <= m; ++i) {
            if (s[i - 1] == t[j - 1]) {
              substitutionCost = 0;
            } else if (tolower(s[i - 1]) == tolower(t[j - 1])) {
                substitutionCost = 1;
            } else {
                substitutionCost = 2;
            }
            int a = dist[i - 1][j] + deletionCost;
            int b = dist[i][j - 1] + insertionCost;
            int c = dist[i - 1][j - 1] + substitutionCost;
            dist[i][j] = min(min(a, b), c);
        }
    }

    k = dist[m][n];

    for (int i = 0; i < m; ++i) {
        free(dist[i]);
    }

    return k;
}

int main()
{
    char s[10001], t[10001];
    int  m, n, d;

    while (scanf("%s %s", s, t) == 2) {
        d = editDistance(s, t, (int) strlen(s), (int) strlen(t));
        fprintf(stderr, "%s %s %d\n", s, t, d);
        printf("%d\n", d);
    }

    return 0;
}

