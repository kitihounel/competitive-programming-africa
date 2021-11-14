#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    string s;

    cin >> t;
    while (t > 0)
    {
        cin >> s;
        for (auto &ch: s) {
            if (ch != s[0]) {
                swap(ch, s[0]);
                break;
            }
        }
        cout << s << endl;
        --t;
    }
    
    return 0;
}
