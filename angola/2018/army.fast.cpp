/**
 * Given the way the battle goes, there will always a winner.
 * But judges can be sneaky and give a test case when both armies
 * have no soldier. In that case, there will be no winner.
 */
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int t, g, m;
    int strength, godMax, mechaMax;

    scanf("%d\n", &t);
    while (t > 0) {
        scanf("%d %d", &g, &m);

        godMax = -1;
        for (int j = 0; j < g; ++j) {
            scanf("%d", &strength);
            godMax = max(strength, godMax);
        }

        mechaMax = -1;
        for (int j = 0; j < m; ++j) {
            scanf("%d", &strength);
            mechaMax = max(strength, mechaMax);
        }

        if (g == 0 && m == 0)
            printf("uncertain");
        else
            printf("%sGodzilla\n", mechaMax > godMax ? "Mecha": "");

        --t;
    }

    return 0;
}

