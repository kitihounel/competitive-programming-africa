#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, P, Q;
    int k;
    vector<int> v;

    scanf("%d\n", &N);
    for (int j = 0; j < N; ++j) {
        scanf("%d", &k);
        v.push_back(k);
    }
    sort(v.begin(), v.end());

    scanf("%d %d\n", &P, &Q);

    for (int j = 0; j < P; ++j) {
        scanf("%d", &k);
        auto it = lower_bound(v.begin(), v.end(), k);
        printf("%s\n", *it == k? ":)": ":(");
    }

    for (int j = 0; j < Q; ++j) {
        scanf("%d", &k);
        printf("%d\n", v[k-1]);
    }

    return 0;
}

