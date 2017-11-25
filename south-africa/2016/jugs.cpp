#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>

using namespace std;
using vi = vector<int>;

const size_t maxNumberOfStates = 28629151;

int N;
int goal;
vi  capacities;

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

int toBase31(const vi &state)
{
    int v = 0;

    for (const auto &j: state)
        v = v * 31 + j;

    return v;
}

int generate(const vi &state, const int &depth, bitset<maxNumberOfStates> &states, deque<pair<vi, int>> &queue)
{
    for (int j = 0; j < N; ++j) {
        // If the current jug is not empty, empty it.
        if (state[j] != 0) {
            auto t = state;

            t[j] = 0;
            if (find(t.begin(), t.end(), goal) != t.end())
                return depth + 1;
            else {
                auto v = toBase31(t);
                
                if (!states[v]) {
                    states.set(v);
                    queue.emplace_back(t, depth + 1);
                }
            }
        }

        // If the current jug is not full, fill it.
        if (state[j] != capacities[j]) {
            auto t = state;

            t[j] = capacities[j];
            if (find(t.begin(), t.end(), goal) != t.end())
                return depth + 1;
            else {
                auto v = toBase31(t);

                if (!states[v]) {
                    states.set(v);
                    queue.emplace_back(t, depth + 1);
                }
            }
        }

        // Pour water in other jugs.
        for (int i = 0; i < N; ++i) {
            if (i == j)
                continue;

            auto t = state;
            auto m = min(t[j], capacities[i] - state[i]);

            for (int k = 0; k < N; ++k) {
                if (k == i)
                    t[k] = state[k] + m;
                else if (k == j)
                    t[k] = state[k] - m;
            }

            if (find(t.begin(), t.end(), goal) != t.end())
                return depth + 1;
            else {
                auto v = toBase31(t);

                if (!states[v]) {
                    states.set(v);
                    queue.emplace_back(t, depth + 1);
                }
            }
        }
    }

    return -1;
}

int main()
{
    int answer, capacity;

    while (cin >> N >> goal) {
        auto m = 0;

        for (int j = 0; j < N; ++j) {
            cin >> capacity;
            capacities.push_back(capacity);
            m = max(m, capacity);
        }

        answer = -1;
        if (goal <= m && goal % gcd(capacities) == 0) {
            bitset<maxNumberOfStates> states;
            deque<pair<vi, int>> queue;
            auto start = vi(N, 0);
            int j = 0;

            states.set(toBase31(start));
            queue.emplace_back(start, 0);
            while (!queue.empty() && answer == -1) {
                const auto &p = queue.front();

                answer = generate(p.first, p.second, states, queue);
                queue.pop_front();
            }
        }

        cout << answer << endl;
        capacities.clear();
    }

    return 0;
}

