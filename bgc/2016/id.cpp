#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <cctype>

using namespace std;

inline bool isvowel(char c)
{
    if (isupper(c)) {
        c = tolower(c);
    }
    return ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main()
{
    string name, surname, code;
    map<string, int> m;

    while(cin >> surname >> name) {
        for (const auto &ch: name) {
            if (!isvowel(ch)) code.push_back(toupper(ch));
            if (code.length() == 4ul) break;
        }
        code.append(4ul - code.length(), 'Z');

        for (const auto &ch: surname) {
            if (isvowel(ch)) code.push_back(toupper(ch));
            if (code.length() == 6ul) break;
        }
        code.append(6ul - code.length(), 'Z');

        printf("%s%03d\n", code.c_str(), m[code]++);

        name.clear();
        surname.clear();
        code.clear();
    }

    return 0;
}
