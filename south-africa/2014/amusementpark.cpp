/**
 * Simulation problem.
 * The solution is to simulate the arrival of the customers at the rides and
 * to count the number of free rides that will be given.
 * Note that there will be at least N free rides given.
 */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int  a, n;
    long long int freeRideCount;

    while(cin >> n && n != -1) {
        vector<int> next(n);
        for(int i = 0; i < n; i++) {
            cin >> a;
            next[i] = a - 1;
        }

        freeRideCount = n;
        for(int i = 0; i < n; i++) {
            vector<bool> takenRides(n, false);
            int currentRide, nextRide;

            currentRide = i;
            nextRide    = next[currentRide];
            takenRides[currentRide] = true;
            while (!takenRides[nextRide]) {
                ++freeRideCount;
                takenRides[nextRide] = true;
                currentRide = nextRide;
                nextRide    = next[currentRide];
            }
        }

        cout << freeRideCount << endl;
    }

    return 0;
}

