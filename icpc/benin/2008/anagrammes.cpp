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
        cout << s << " et " << t << " ";

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s == t) {
            cout << "sont des anagrammes l'un pour l'autre" << endl;
        } else {
            cout << "ne sont pas des anagrammes l'un pour l'autre" << endl;
        }

        --n;
    }

    return 0;
}

