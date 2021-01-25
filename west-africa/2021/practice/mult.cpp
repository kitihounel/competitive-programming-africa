#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;
using i64 = long long int;

int main()
{
    int t, n, k;
    i64 a, p;

    ios::sync_with_stdio(false);
    scanf("%d", &t);
    while (t > 0) {
        scanf("%d %d", &n, &k);

        vector<i64> v(n);

        for (int i = 0; i < n; ++i) {
            scanf("%lld", &a);
            v[i] = a;
        }
        sort(begin(v), end(v));

        p = 1ll;
        for (int i = n - 1; k > 0; --i, --k) {
            p *= v[i];
        }

        printf("%lld\n", p);
        --t;
    }

    return 0;
}
