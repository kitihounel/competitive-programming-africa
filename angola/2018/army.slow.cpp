/**
 * This program just simulates the battle.
 */
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t, g, m;
    int strength;
    vector<int> god, mecha;

    scanf("%d\n", &t);
    while (t > 0) {
        scanf("%d %d", &g, &m);

        for (int j = 0; j < g; ++j) {
            scanf("%d", &strength);
            god.push_back(strength);
        }

        for (int j = 0; j < m; ++j) {
            scanf("%d", &strength);
            mecha.push_back(strength);
        }

        sort(god.rbegin(), god.rend());
        sort(mecha.rbegin(), mecha.rend());

        while (!god.empty() && !mecha.empty()) {
            if (god.back() >= mecha.back())
                mecha.pop_back();
            else
                god.pop_back();
        }

        if (god.empty() && mecha.empty())
            printf("uncertain");
        else
            printf("%sGodzilla\n", god.empty()? "Mecha": "");

        mecha.clear();
        god.clear();
        --t;
    }

    return 0;
}

