#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
using i64 = long long int;

int main()
{
    int n;
    string inputBase, outputBase, number;

    cin >> n;
    for (int t = 1; t <= n; ++t) {
        cin >> number >> inputBase >> outputBase;

        // We get the values of input base digits.
        map<char, i64> inputBaseDigits;
        i64 d = 0ll;
        for (const auto &ch: inputBase) inputBaseDigits[ch] = d++;

        // We convert the input number in base 10.
        i64 v = 0ll;
        for (const auto &ch: number) {
            v = v * (i64) inputBase.length() + inputBaseDigits[ch];
        }

        // We convert the number in the output base.
        string result;
        do {
            d  = v % (i64) outputBase.length();
            v /= (i64) outputBase.length();
            result.push_back(outputBase[d]);
        } while(v != 0ll);

        reverse(result.begin(), result.end());
        cout << "Alien #" << t << ": " << result << endl;
    }

    return 0;
}
