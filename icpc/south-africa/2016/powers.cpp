#include <iostream>
#include <map>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    int r;

    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int gcd(const vector<int> &v)
{
    int d = 0;

    for (const auto &n: v) {
        d = gcd(n, d);
    }

    return d;
}

map<int, int> primeFactorization(int n)
{
    int i = 2;
    map<int, int> f;

    while (i * i <= n) {
        while (n % i == 0) {
            n /= i;
            ++f[i];
        }
        i += (i & 1) + 1;
    }
    if (n != 1) {
        ++f[n];
    }

    return f;
}

int pow(int b, int e)
{
    int p = 1;

    while (e != 0) {
        if (e % 2 == 1) {
            p *= b;
        }
        b *= b;
        e /= 2;
    }

    return p;
}

void solve(int n)
{
    map<int, int> f = primeFactorization(n);
    vector<int> powers;
    int a, b;

    for (const auto &p: f) {
        powers.push_back(p.second);
    }
    a = 1;
    b = gcd(powers); 
    for (const auto &p: f) {
        a *= pow(p.first, p.second / b);
    }
    cout << a << "^" << b << endl;
}

int main()
{
    int n;

    while (cin >> n && n != -1) {
        solve(n);
    }
}

