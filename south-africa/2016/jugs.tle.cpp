#include <iostream>
#include <set>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;
using vi = vector<int>;

int N;
int goal;
vi  capacities;
set<vi> states;
deque<pair<vi, int>> queue;

int gcd(int a, int b)
{
    int r;

    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int gcd(const vi &numbers)
{
    int d = numbers[0];

    for (int j = 1; j < (int) numbers.size() && d != 1; ++j)
        d = gcd(d, numbers[j]);

    return d;
}

int generate(const vi &state, int depth)
{
    for (int j = 0; j < N; ++j) {
        // If the current jug is not empty, empty it.
        if (state[j] != 0) {
            auto t = state;

            t[j] = 0;
            if (find(t.begin(), t.end(), goal) != t.end())
                return depth + 1;
            else if (states.find(t) == states.end() && goal % gcd(t) == 0) {
                states.insert(t);
                queue.push_back(make_pair(t, depth + 1));
            }
        }

        // If the current jug is not full, fill it.
        if (state[j] != capacities[j]) {
            auto t = state;

            t[j] = capacities[j];
            if (find(t.begin(), t.end(), goal) != t.end())
                return depth + 1;
            else if (states.find(t) == states.end() && goal % gcd(t) == 0) {
                states.insert(t);
                queue.push_back(make_pair(t, depth + 1));
            }
        }

        // Pour water in other jugs.
        for (int i = 0; i < N; ++i) {
            if (i == j)
                continue;

            auto t = state;
            auto m = min(state[j], capacities[i] - state[i]);

            for (int k = 0; k < N; ++k) {
                if (k == i)
                    t[k] = state[k] + m;
                else if (k == j)
                    t[k] = state[k] - m;
            }

            if (find(t.begin(), t.end(), goal) != t.end())
                return depth + 1;
            else if (states.find(t) == states.end() && goal % gcd(t) == 0) {
                states.insert(t);
                queue.push_back(make_pair(t, depth + 1));
            }
        }
    }

    return -1;
}

int main()
{
    int capacity;

    while (cin >> N >> goal) {
        for (int j = 0; j < N; ++j) {
            cin >> capacity;
            capacities.push_back(capacity);
        }

        auto m = max_element(capacities.begin(), capacities.end());

        if (goal <= *m && goal % gcd(capacities) == 0) {
            auto start  = vi(N, 0);
            auto answer = -1;

            states.insert(start);
            queue.push_back(make_pair(start, 0));
            while (!queue.empty() && answer == -1) {
                auto &p = queue.front();

                answer = generate(p.first, p.second);
                queue.pop_front();
            }

            cout << answer << endl;
        } else
            cout << -1 << endl;

        capacities.clear();
        queue.clear();
        states.clear();
    }

    return 0;
}

