#include <iostream>
#include <vector>

using namespace std;

// Can be repaced by pair<int, int>.
typedef struct Point {
    int i, j;
} Point;

int check(const vector<vector<int>> &m, const int x, const Point &g)
{
    int ok = 1;

    for (int i = g.i; i < g.i + x && ok; ++i) {
        for (int j = g.j; j < g.j + x && ok; ++j) {
            auto si = i - g.i;
            auto sj = j - g.j;

            auto b = si;
            auto a = x - sj - 1;

            ok = m[i][j] == m[a + g.i][b + g.j];
        }
    }

    return ok;
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
