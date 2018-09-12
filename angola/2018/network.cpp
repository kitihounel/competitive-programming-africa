/**
 * Generate all permutations of the computers and compute for each permutation
 * the length of cable needed to connect adjacent computers.
 * The answer is the minimum of the permutations.
 * Complexity: O(N!)
 * There is at most 10 computers, so in the hardest case, we (only) need to perform
 * 10! = 3628800 calls to next_permutation().
 */
#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

using Point = pair<int, int>;

double distance(const Point &p, const Point &q)
{
    auto dx = p.first - q.first;
    auto dy = p.second - q.second;

    return sqrt(dx * dx + dy * dy);
}

int main()
{
    vector<Point> v;
    int N, x, y;

    scanf("%d\n", &N);
    for (int j = 0; j < N; ++j) {
        scanf("%d %d\n", &x, &y);
        v.push_back(Point(x, y));
    }
    sort(v.begin(), v.end());

    auto cost = numeric_limits<double>::max();
    
    do {
        auto f = 0.0;
        auto i = v.begin();
        auto j = i + 1;

        while (j != v.end()) {
            f += distance(*i, *j);
            ++i;
            ++j;
        }
        cost = min(cost, f);
    } while (next_permutation(v.begin(), v.end()));

    printf("%.2lf\n", cost);

    return 0;
}

