/**
 * We use a union-find structure to find the connected components of the graph.
 */
#include <cstdio>
#include <vector>
#include <numeric>

using namespace std;

const int MAX_N = 10000;

vector<int> parents(MAX_N + 1, 0);

int find(int x)
{
    vector<int> q;

    while (x != parents[x]) {
        q.push_back(x);
        x = parents[x];
    }

    for (const auto &j: q)
        parents[j] = x;

    return x;
}

int unite(int x, int y)
{
    parents[find(x)] = find(y);
}

int main()
{
    int a, b, m, n;
    int k, t;

    scanf("%d\n", &t);
    while (t > 0) {
        scanf("%d %d\n", &n, &m);
        iota(parents.begin(), parents.end(), 0);
        for (int j = 0; j < m; ++j) {
            scanf("%d %d\n", &a, &b);
            unite(a, b);
        }

        k = 0;
        for (int j = 1; j <= n; ++j) {
            if (find(j) == j)
                ++k;
        }

        printf("%d\n", (k * (k - 1)) / 2);
        --t;
    }

    return 0;
}

