#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, p, r;
    string s, t;

    cin >> p;
    while (p > 0) {
        cin >> n >> r >> s;

        for (const auto &ch: s) {
            t.append(r, ch);
        }
        cout << n << " " << t << endl;

        t.clear();
        --p;
    }

    return 0;
}

