#include <iostream>
#include <vector>

using namespace std;

// Can be repaced by pair<int, int>.
typedef struct Point {
    int i, j;
} Point;

int check(const vector<vector<int>> m, int x, const Point &p)
{
    int b = 1;

    for (int i = p.i; i < p.i + x && b; ++i) {
        for (int j = p.j; j < p.j + x && b; ++j) {
            auto ri = i - p.i;
            auto rj = j - p.j;
            auto ti = rj;
            auto tj = x - ri - 1;
            b = m[i][j] == m[ti + p.i][tj + p.j];
        }
    }

    return b;
}

int main()
{
    int n, x;

    cin >> n >> x;

    vector m(n, vector(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> m[i][j];
        }
    }

    int k = 0;

    for (int i = 0; i + x - 1 < n; ++i) {
        for (int j = 0; j + x - 1 < n; ++j) {
            k += check(m, x, Point{i, j});
        }
    }

    cout << k << endl;

    return 0;
}
