/**
 * The solution is just to convert the numbers in base 26 and to use lowercase
 * letters as digits.
 * Note: since there is no zero, we have to decrease the numbers by 1 before
 *       doing from the conversion.
 */
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;
using i64 = long long int;

void solve(i64 n)
{
    string w;
    i64    d;

    while (n != 0) {
        n -= 1;
        d  = n % 26;
        n /= 26;
        w.push_back('a' + d);
    }
    reverse(w.begin(), w.end());
    printf("%s\n", w.c_str());
}

int main()
{
    i64 n;

    while (scanf("%lld\n", &n) > 0 && n != -1) {
        solve(n);
    }

    return 0;
}

