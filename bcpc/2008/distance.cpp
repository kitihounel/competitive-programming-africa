/**
 * The solution is to determine the intersection of the two input strings, i.e.
 * characters that belong to both strings. Note that a character can appear
 * several times in the intersection.
 * The anagramic distance between the two strings is then:
 *      sum of lengths of the two strings - 2 * length of the intersection.
 */
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string word1, word2;
    string inter;
    int    n;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> word1 >> word2;

        // We need to sort the string in order to determine their intersection.
        sort(word1.begin(), word1.end());
        sort(word2.begin(), word2.end());
        // We reserve space for the intersection of the two sets. The size of
        // the intersection is at most min( word1.length(), word2.length() )
        inter = string('#', min(word1.length(), word2.length()));
        auto it = set_intersection(word1.begin(), word1.end(),
                                   word2.begin(), word2.end(),
                                   inter.begin());
        inter.erase(it, inter.end());

        cout << "Case #" << i + 1 << ": " \
                word1.length() + word2.length() - 2 * inter.length() << endl;
    }


    return 0;
}

