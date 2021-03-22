/**
 * This program tried to find the wave amplitude using binary search over real numbers.
 * See this thread on So for more: stackoverflow.com/questions/2440263.
 */
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const auto pi = 3.141592653589793238462643383279502884L;
long double a, v, w;
int n;

long double computeArclength()
{
    auto L = v / n;
    auto c = 2 * pi * a / L;
    auto k = sqrt((c * c) / (1 + c * c));

    return (2 * L / pi) * sqrt(1 + c) * ellint_2l(k, pi / 2);
}

int main()
{
    long double l;

    while (cin >> w >> v >> n) {
        auto lo = 0.0L;
        auto hi = sqrt(w * w - v * v) / (2 * n);
        auto target = w / n;
        auto eps = 0.1L;

        while (eps > 0.000001L) {
            a = (lo + hi) / 2;
            l = computeArclength();
            eps = fabs(target - l);
            if (l >= target) {
                hi = a;
            } else {
                lo = a;
            }
        }
        cout << setprecision(3) << fixed << a - fmod(a, 0.001) << endl;
    }

    return 0;
}

