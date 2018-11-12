#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int integerSquareRoot(int n)
{
    int shift, shifted;
    int root, candidate;

    if (n == 1) {
        return 1;
    }

    shift = 2;
    shifted = (n >> 2);
    while (shifted != 0 && shifted != n) {
        shift += 2;
        shifted = (n >> shift);
    }

    shift -= 2;
    root = 0;
    while (shift >= 0) {
        root = (root << 1);
        candidate = root + 1;
        if (candidate * candidate <= (n >> shift)) {
            root = candidate;
        }
        shift -= 2;
    }

    return root;
}

int main()
{
    int n, root;

    while (cin >> n && n != -1) {
        vector<int> v;
        
        while (n != 0) {
            root = min(100, integerSquareRoot(n));
            v.push_back(root);
            n -= root * root;
        }

        for (const auto &r: v) {
            cout << r << "^" << r << " ";
        }
        cout << endl;
    }

    return 0;
}

