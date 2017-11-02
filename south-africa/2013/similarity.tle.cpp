/**
 * This problem is about Levenshtein distance.
 *
 * You can find an introduction at:
 * https://en.wikipedia.org/wiki/Levenshtein_distance
 *
 * A very good explaination of the algorithm is given at:
 * http://blog.ce-se.de/2010/10/11/levenshtein-distance-edit-distance-easily-explained/
 *
 * This program is based on the algorithm given in the Wikipedia's article.
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>

using namespace std;

int editDistance(const string &s, const string &t)
{
    int deletionCost, insertionCost, substitutionCost;
    int m = (int) s.length();
    int n = (int) t.length();
    // Input strings can be 10000 characters long, we can't use arrays.
    vector<vector<int>> dist(m + 1, vector<int>(n + 1, 0));
    
    insertionCost = deletionCost = 2;

    for (int i = 0; i <= m; ++i)
        dist[i][0] = i * deletionCost;

        for (int j = 0; j <= n; ++j)
        dist[0][j] = j * insertionCost;

    for (int j = 1; j <= n; ++j) {
        for (int i = 1; i <= m; ++i) {

            if (s[i-1] == t[j-1])
              substitutionCost = 0;
            else if (tolower(s[i-1]) == tolower(t[j-1]))
                substitutionCost = 1;
            else
                substitutionCost = 2;

            int a = dist[i-1][j] + deletionCost;
            int b = dist[i][j-1] + insertionCost;
            int c = dist[i-1][j-1] + substitutionCost;

            dist[i][j] = min(min(a, b), c);
        }
    }

    return dist[m][n];
}

int main()
{
    string src, dst;

    while (cin >> src >> dst)
        cout << editDistance(src, dst) << endl;

    return 0;
}

