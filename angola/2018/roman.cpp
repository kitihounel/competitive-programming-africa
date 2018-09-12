/**
 * Explaination of the conversion algorithm:
 * https://www.geeksforgeeks.org/converting-roman-numerals-decimal-lying-1-3999/
 * 
 * Note: our implementation if the conversion algorithm is a little overkill,
 * but there is no reversed for-loop in C++.
 */
#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, int> conv{ { 'I', 1 }, { 'V', 5 }, { 'X', 10 }, { 'L', 50 }, { 'C', 100 }, { 'D', 500}, { 'M', 1000 } };

int convert(string s)
{
    int v, current, previous;
    auto it = s.rbegin();

    v = previous = 0;
    while (it != s.rend()) {
        current = conv[*it];
        if (current >= previous)
            v += current;
        else
            v -= current;
        previous = current;
        ++it;
    }
    
    return v;
}

int main()
{
    string s;
    int t, v;

    cin >> t;
    while (t > 0) {
        cin >> s;
        v = convert(s);
        cout << (v % 3 == 0? "YES": "NO") << " " << v << endl;
        --t;
    }

    return 0;
}

