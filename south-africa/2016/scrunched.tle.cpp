/**
 * This program uses the triangle method to compute the arclength.
 * It finds the amplitude of the sine wave with binary search over real numbers.
 */
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const auto pi = 3.141592653589793238462643383279502884L;
long double a, v, w;
int n;

long double f(long double x)
{
    return a * sin(2 * pi * n * x / v);
}

long double computeArclength()
{
    auto x = 0.0L;
    auto l = 0.0L;
    auto dx = 0.0001L;

    while (x <= v / (4 * n)) {
        auto dy = fabsl(f(x) - f(x + dx));
        l += sqrt(dx * dx + dy * dy);
        x += dx;
    }

    return l;
}

int main()
{
    long double l;

    while (cin >> w >> v >> n) {
        auto lo = 0.0L;
        auto hi = sqrt(w * w - v * v) / (2 * n);
        auto target = w / n;
        auto eps = 0.1L;

        while (eps > 0.0001L) {
            a = (lo + hi) / 2;
            l = computeArclength() * 4;
            if (l >= target) {
                hi = a;
            } else {
                lo = a;
            }
            eps = fabs(target - l);
        }
        cout << setprecision(3) << fixed << a - fmod(a, 0.001) << endl;
    }

    return 0;
}

