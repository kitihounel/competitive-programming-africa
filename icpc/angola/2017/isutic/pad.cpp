#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
using vi = vector<int>;

/**
 * For explainations about this function, consult the following page:
 * https://geeksforgeeks.org/find-all-divisors-of-a-natural-number-set-2/
 */
vi getProperDivisors(int n)
{
    vi lo, hi;

    if (n != 1) lo.push_back(1);
    for (int f = 2; f * f <= n; ++f) {
        if (n % f != 0) continue;
        int q = n / f;
        lo.push_back(f);
        if (q != f) hi.push_back(q);
    }
    lo.insert(lo.end(), hi.begin(), hi.end());

    return lo;
}

int main()
{
    vi  divisors;
    int n, t, sum;

    cin >> t;
    while (t > 0) {
        cin >> n;
        divisors = getProperDivisors(n);
        sum = accumulate(divisors.begin(), divisors.end(), 0);
        cout << (sum == n? "perfect": (sum < n? "deficient": "abundant")) << endl;
        --t;
    }

    return 0;  
}

