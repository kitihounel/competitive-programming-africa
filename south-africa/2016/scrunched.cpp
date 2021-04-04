#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const auto pi = 3.141592653589793238462643383279502884L;
long double a, v, w;
int n;

long double arclength()
{
    auto c = 2 * a * pi * n / v;
    auto k = c / sqrt(1 + c * c);

    return sqrt(1 + c * c) * ellint_2l(k, 2 * pi) * v / (2 * pi * n);
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
            l = arclength();
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

