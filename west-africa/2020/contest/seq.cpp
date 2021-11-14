#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    int n;

    cin >> n;

    vector seq(n,  0);
    
    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
    }
    
    int category = -1;
    auto it = is_sorted_until(begin(seq), end(seq));

    if (it == end(seq)) {
        category = 1;
    } else if ( it != begin(seq) + 1 && is_sorted(it, end(seq), greater<int>()) ) {
        category = 3;
    } else if ( is_sorted(rbegin(seq), rend(seq)) ) {
        category = 2;
    } else {
        category = 4;
    }

    cout << category << endl;

    return 0;
}
