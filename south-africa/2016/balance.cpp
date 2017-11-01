#include <iostream>
#include <cstdio>

using namespace std;
using i64 = long long int;

i64 gcd(i64 a, i64 b)
{
    i64 r;

    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

i64 lcm(i64 a, i64 b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    i64 a, m, n;

    while (scanf("%lld %lld", &n, &a) == 2) {
        m = 1;
        for (i64 i = a; i >= 0; --i) {
            m = lcm(m, n - i);
        }
        printf("%lld\n", m);
    }

    return 0;
}

