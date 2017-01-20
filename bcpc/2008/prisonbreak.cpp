/**
 * I found two ways to solve this problem.
 *      1. Use a kind of Eratosthenus sieve to simulate the evolution of the
 *         game.
 *      2. One can notice that the number of times a cell is opened or closed
 *         is the number of divisors of its index. So if the number of divisors
 *         of a cell is even, the cell will be left closed. But if this number
 *         is odd, the cell will be left opened.
 *
 * Only the first solution is implemented here :-)
 */
#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

int solve(int n)
{
    std::vector<bool> v(n, true);

    for (int i = 2; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            v[j - 1] = !v[j - 1];
        }
    }

    return (int) std::count(v.begin(), v.end(), true);
}

int main()
{
    int m, n;

    cin >> m;
    while (m > 0) {
        cin >> n;
        cout << solve(n) << endl;
        --m;
    }

    return 0;
}

