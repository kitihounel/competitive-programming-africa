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
#include <cctype>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;

const int deletionCost  = 2;
const int insertionCost = 2;

int editDistance(const string &src, const string &dst)
{
    int substitutionCost;
    int m = (int) src.length();
    int n = (int) dst.length();
    vi  previousRow(n + 1, 0);
    vi  currentRow(n + 1,  0);
    
    for (int j = 0; j <= n; ++j)
        previousRow[j] = j * insertionCost;

    for (int i = 1; i <= m; ++i) {
        currentRow[0] = i * deletionCost;

        for (int j = 1; j <= n; ++j) {

            if (src[i-1] == dst[j-1])
                substitutionCost = 0;
            else if (tolower(src[i-1]) == tolower(dst[j-1]))
                substitutionCost = 1;
            else
                substitutionCost = 2;

            int a = currentRow[j-1]  + deletionCost;
            int b = previousRow[j]   + insertionCost;
            int c = previousRow[j-1] + substitutionCost;

            currentRow[j] = min(min(a, b), c);
        }
        swap(previousRow, currentRow);
    }

    return previousRow[n];
}

int main()
{
    string src, dst;

    while (cin >> src >> dst)
        cout << editDistance(src, dst) << endl;

    return 0;
}

