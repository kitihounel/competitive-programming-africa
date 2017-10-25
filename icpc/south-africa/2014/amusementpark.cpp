/**
 * Simulation problem.
 * The solution is to simulate the arrival of the customers at the rides and
 * to count the number of free rides that will be given per customer.
 * Note that there will be at least N free rides given.
 */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int  a, n;
    long long int freeRideCount;
    vector<int> v;

    v.reserve(150000ul);

    while (cin >> n && n != -1) {

        for (int j = 0; j < n; ++j) {
            cin >> a;
            v.push_back(a - 1);
        }

        freeRideCount = n;
        for (int j = 0; j < n; ++j) {
            vector<bool> takenRides(n, false);
            int currentRide, nextRide;

            currentRide = j;
            nextRide = v[currentRide];
            takenRides[currentRide] = true;
            while (!takenRides[nextRide]) {
                ++freeRideCount;
                takenRides[nextRide] = true;
                currentRide = nextRide;
                nextRide = v[currentRide];
            }
        }

        cout << freeRideCount << endl;
        v.clear();
    }

    return 0;
}

