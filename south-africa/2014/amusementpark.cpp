#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
using i64 = long long int;

int main()
{
    int  a, n;
    vector<int> next;

    while (cin >> n && n != -1) {
        vector<bool> visited(n, false);
        vector<bool> computed(n, false);
        vector<i64>  tripLengths(n, 0ll);

        for (int j = 0; j < n; ++j) {
            cin >> a;
            next.push_back(a - 1);
        }

        for (int j = 0; j < n; ++j) {
            if (computed[j])
                continue;

            vector<int>  q;
            int currentRide;
            i64 rideCount = 0ll;

            fill(visited.begin(), visited.end(), false);
            currentRide = j;
            while (!visited[currentRide]) {
                if (computed[currentRide]) {
                    rideCount += tripLengths[currentRide];
                    break;
                }

                ++rideCount;
                visited[currentRide] = true;
                q.push_back(currentRide);
                currentRide = next[currentRide];
            }

            int k = 0;
            while (q[k] != currentRide && k < (int) q.size()) {
                computed[q[k]] = true;
                tripLengths[q[k]] = rideCount - (i64) k;
                ++k;
            }

            i64 cycleLength = rideCount - (i64) k;
            while (k < (int) q.size()) {
                computed[q[k]] = true;
                tripLengths[q[k]] = cycleLength;
                ++k;
            }
        }

        cout << accumulate(tripLengths.begin(), tripLengths.end(), 0ll) << endl;
        next.clear();
    }

    return 0;
}

