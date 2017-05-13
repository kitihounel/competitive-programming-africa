/**
 * Solution: remove each vertex from the network and count the number of
 * connected components remaining by using a BFS.
 * This solution is not very efficient, but since we have a time limit of 20s,
 * it will do the work.
 */
#include <iostream>
#include <stdio.h>
#include <set>
#include <deque>
#include <map>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;
using vi = vector<int>;

int main()
{
    int u, v;    
    int t;

    t = 1;
    while (cin.peek() != 48) {
        vector<vi> adjl(1001);
        set<int>   vertices;
        map<int, int> spf;
        
        while (cin >> u && u != 0 && cin >> v) {
            adjl[u].push_back(v);
            adjl[v].push_back(u);
            vertices.insert(u);
            vertices.insert(v);
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (const auto &u: vertices) {
            vector<bool> visited(vertices.size() + 1ul, false);
            set<int> verticesCopy = vertices;
            int subnetCount;

            subnetCount = 0;
            verticesCopy.erase(u);
            while (!verticesCopy.empty()) {
                ++subnetCount;

                deque<int> queue;
                queue.push_back(*(verticesCopy.begin()));
                visited[*(verticesCopy.begin())] = true;
                while (!queue.empty()) {
                    v = queue.front();
                    for (const auto &w: adjl[v]) {
                        // We should not use the current vertex u in the BFS.
                        if (w != u && !visited[w]) {
                            queue.push_back(w);
                            visited[w] = true;
                        }
                    }
                    queue.pop_front();
                    verticesCopy.erase(v);
                }
            }

            if (subnetCount != 1) {
                spf[u] = subnetCount;
            }
        }

        if (t > 1) {
            std::cout << std::endl;
        }
        cout << "Network #" << t << endl;
        if (spf.size() == 0ul) {
            std::cout << "No SPF nodes" << std::endl;
        } else {
            for (const auto &p: spf) {
                cout << "SPF node " << p.first << " leaves " << p.second
                     << " subnets"  << endl;
            }
        }

        ++t;
    }

    return 0;
}
