/**
 * The solution implemented here is just to sort the two strings and to test if
 * they are equal.
 */
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    string s, t;

    cin >> n;
    while (n > 0) {
        cin >> s >> t;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s == t) {
            printf("%s et %s sont des anagrammes l'un pour l'autre\n", \
                   s.c_str(), t.c_str());
        } else {
            printf("%s et %s ne sont pas des anagrammes l'un pour l'autre\n", \
                   s.c_str(), t.c_str());
        }

        --n;
    }

    return 0;
}

