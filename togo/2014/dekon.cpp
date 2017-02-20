#include <iostream>
#include <string>
#include <regex>
#include <vector>

using namespace std;

int main()
{
    int p, n;
    string s;
    regex  rgx;
    /* I have no idea of how this works. */
    const  char *sequences[] = {
        "(?=(TTT)).", "(?=(TTH)).", "(?=(THT)).", "(?=(THH)).",
        "(?=(HTT)).", "(?=(HTH)).", "(?=(HHT)).", "(?=(HHH))."
    };

    cin >> p;
    while (p > 0) {
        cin >> n >> s;

        cout << n;
        for (const char *seq: sequences) {
            rgx = regex(seq);
            auto b = sregex_iterator(s.begin(), s.end(), rgx);
            auto e = std::sregex_iterator();
            cout << " " << distance(b, e);
        }
        cout << endl;

        --p;
    }

    return 0;
}
