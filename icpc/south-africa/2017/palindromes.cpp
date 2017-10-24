/**
 * Note: The code used to test if a word is a palindrome is not very optimal.
 * But it is just a mock contest, so why should we suffer when STL provides
 * a nice way to solve the problem?
 *
 * Here is the best algorithm we know to test if a word is a palindrome.
 * let w be the word to test
 * let n be the length of n
 * If w is a palidrome, then w[j] = w[n-1-j] for j in [0, n/2[
 */
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s;

    while (cin >> s && s != "-1") {
        bool b = equal(s.begin(), s.end(), s.rbegin());
        cout << (b ? "yes" : "no") << endl;
    }

    return 0;
}

