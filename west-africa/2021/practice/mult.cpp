#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    int t, n, k;
    int a, p;

    ios::sync_with_stdio(false);
    scanf("%d", &t);
    while (t > 0) {
        scanf("%d %d", &n, &k);

        vector<int> v(n);

        for (int i = 0; i < n; ++i) {
            scanf("%d", &a);
            v[i] = a;
        }
        sort(begin(v), end(v));

        p = 1;
        for (int i = n - 1; k > 0; --i, --k) {
            p *= v[i];
        }

        printf("%d\n", p);
        --t;
    }

    return 0;
}
