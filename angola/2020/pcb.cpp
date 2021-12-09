#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <experimental/iterator>
#include <iterator>

int main()
{
    using namespace std;

    int t, n, m;
    int u;

    cin >> t;
    while (t > 0) {
        cin >> n >> m;

        vector<int> v;

        for (int i = 0; i < n; ++i) {
            cin >> u;
            v.push_back(u);
        }

        set<int> s(begin(v), end(v));
        vector<int> scores;
        int k = 0;

        for (int i = 0; i < m; ++i) {
            cin >> u;
            auto it = s.lower_bound(u);
            if (it != end(s)) {
                ++k;
                s.erase(it);
            }
            scores.push_back(k);
        }

        copy(begin(scores), end(scores), experimental::make_ostream_joiner(cout, " "));
        cout << endl;

        --t;
    }

    return 0;
}

