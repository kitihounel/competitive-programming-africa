#include <iostream>
#include <vector>

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

        bool possible = true;

        for (int i = n - 1; i > 0; --i) {
            if (v[i] > v[i-1]) {
                continue;
            }
            
            int d = v[i-1] - v[i] + 1;

            if (d <= a[i-1]) {
                v[i-1] -= d;
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
