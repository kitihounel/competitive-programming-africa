#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
    int n, l;
    long double theta, radius;

    while (cin >> n >> l) {
        theta = M_PIl * 2.0l / n;
        radius = ((long double) l) / (2 * tan(theta / 2.0l));
        printf("%.3Lf\n", radius * 2.0l);
    }

    return 0;
}

