/**
 * Shortest path problem, solved using Dijkstra algorithm.
 * The implementation of the algorithm used here is not very optimal.
 * While building the BFS tree, a node can be inserted several times in the
 * queue of unvisited nodes.
 * The code is based on the one presented here:
 * geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef struct town {
    string name;
    int distance;
    town(const string &s, const int &d): name(s), distance(d) {}
} Town;

bool operator < (const Town &n, const Town &o)
{
    return o.distance < n.distance;
}

int main()
{
    int n, p;
    string src, dst;
    map<string, int> subtree;
    map<string, vector<Town>> adjacencyMap;
    vector<Town> queue;

    cin >> p;
    while (p > 0) {
        cin >> n >> src >> dst;

        while (n > 0) {
           string src, dst;
           int d;
           cin >> src >> dst >> d;
           adjacencyMap[src].emplace_back(dst, d);
           adjacencyMap[dst].emplace_back(src, d);
           --n;
        }

        /* Shortest path algorithm is implemented here. */
        queue.emplace_back(src, 0);
        while (!queue.empty()) {
            make_heap(queue.rbegin(), queue.rend(), less<Town>());

            Town u = queue.back();
            /* Since we are using a vector and not a deque for the queue,   */
            /* we should remove the top element here because ohter elements */
            /* can be added in the queue it while visiting neighboors.      */
            queue.pop_back();
            if (subtree.find(u.name) == subtree.end()) {
                for (const auto &v : adjacencyMap[u.name]) {
                    if (subtree.find(v.name) == subtree.end()) {
                        queue.emplace_back(v.name, u.distance + v.distance);
                    }
                }
                subtree.insert(make_pair(u.name, u.distance));
            }
        }

        /* A path always to exist between the two towns, so no need to check */
        /* if the destination town is reachable from the departure town.    */
        cout << src << " " << dst << " " << subtree[dst] << endl;

        adjacencyMap.clear();
        subtree.clear();
        --p;
    }
}
