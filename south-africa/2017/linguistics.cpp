#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string s;
    int n;

    while (cin >> n >> s && n != -1) {
        switch (n) {
        case 0:
            cout << "Bonjour " << s << endl;
            break;
        case 1:
            cout << "Ola " << s << endl;
            break;
        default:
            cout << "Hello " << s << endl;
        }
    }

    return 0;
}

