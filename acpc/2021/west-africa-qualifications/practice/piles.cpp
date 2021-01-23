#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    int t, n, k;

    cin >> t;
    while (t > 0) {
        cin >> n;

        vector<int> v(n);
        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(begin(a), end(a));

        bool possible = true;

        for (int i = n - 1; i > 0; --i) {
            if (v[i] > v[i-1]) {
                continue;
            }
            
            int d = v[i-1] - v[i] + 1;
            auto it = lower_bound(begin(a), end(a), d);

            if (it != end(a)) {
                v[i-1] -= *it;
                if (v[i-1] < 1) {
                    possible = false;
                    break;
                }
            } else {
                possible = false;
                break;
            }
        }

        cout << (possible ? "YES" :  "NO") << endl;
        --t;
    }

    return 0;
}
