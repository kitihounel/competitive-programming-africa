/**
 * Naive solution that will get TLE.
 * This program simulates the arrival of the customers at the rides and count
 * the number of free rides that will be given per customer.
 * There will be at least N free rides given.
 */
#include <iostream>
#include <vector>

using namespace std;
using i64 = long long int;

int main()
{
    int a, n;
    i64 freeRideCount;
    
    while (cin >> n && n != -1) {
        vector<int> v;

        for (int j = 0; j < n; ++j) {
            cin >> a;
            v.push_back(a - 1);
        }

        freeRideCount = 0;
        for (int j = 0; j < n; ++j) {
            vector<bool> visited(n, false);
            int currentRide;

            currentRide = j;
            while (!visited[currentRide]) {
                ++freeRideCount;
                visited[currentRide] = true;
                currentRide = v[currentRide];
            }
        }

        cout << freeRideCount << endl;
    }

    return 0;
}

