#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <cctype>

using namespace std;

inline bool isvowel(const char &ch)
{
    return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}

int main()
{
    string name, surname, id;
    map<string, int> counter;

    while(cin >> name >> surname) {

        for (const auto &ch: surname) {
            if (!isvowel(ch))
                id.push_back(ch);
            if (id.length() == 4ul)
                break;
        }
        id.append(4ul - id.length(), 'Z');

        for (const auto &ch: name) {
            if (isvowel(ch))
                id.push_back(ch);
            if (id.length() == 6ul)
                break;
        }
        id.append(6ul - id.length(), 'Z');

        printf("%s%03d\n", id.c_str(), counter[id]);
        ++counter[id];
        id.clear();
    }

    return 0;
}
