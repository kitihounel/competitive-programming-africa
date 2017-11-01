/**
 * Solution: just check if the numbers are sorted.
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int  n, x;
    bool sorted;
    vector<int> v;

    // We reserve space for hundred elements to avoid reallocation.
    v.reserve(100);
    while (cin >> n && n > 0) {
        for (int i = 0; i < n; ++i) {
            cin >> x;
            v.push_back(x);
        }

        sorted = is_sorted(v.begin(), v.end());
        cout << (sorted? "yes": "no") << endl;

        v.clear();
    }

    return 0;
}

