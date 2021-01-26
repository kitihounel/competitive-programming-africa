#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;

typedef struct Cell {
    int i, j;
} Cell;

inline bool isValid(const Cell &c, const int &n, const int &m)
{
    return c.i >= 0 && c.i < n && c.j >= 0 && c.j < m;
}

int main()
{
    int n, m, q;

    cin >> n >> m >> q;

    vector g(n, vector(m, 0));
    int x, y;

    while (q != 0) {
        cin >> x >> y;
        --x;
        --y;

        vector v{Cell{x, y}, Cell{x, y-1}, Cell{x, y+1}, Cell{x+1, y}, Cell{x-1, y}};

        for (const auto &c: v) {
            if (isValid(c, n, m)) {
                g[c.i][c.j] ^= 1; // Flip the value; 1 -> 0, 0 -> 1.
            }
        }
        --q;
    }

    for (const auto &row: g) {
        ostringstream oss;

        copy(begin(row), end(row), ostream_iterator<int>(oss, " "));
        cout << oss.str() << endl;
    }

    return 0;
}

