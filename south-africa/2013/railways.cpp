/**
 * We have to find the second best minimum spanning tree of a given graph.
 * This solution is based on the explainations by Amandeep Singh on this page:
 *    https://www.quora.com/How-do-I-find-the-second-best-minimum-spanning-tree
 *
 * Description of the process
 *    (1) Sort the edges in O(E log E), then find MST using Kruskal algorithm in O(E).
 *    (2) Now, for each edge in MST (We will have V-1 edges in it) temporarily exclude
 *        it from the edge list so that it cannot be chosen.
 *    (3) Then, again try to find the MST in O(E) (In this we have excluded an edge).
 *    (4) Do this for all the edges in MST, and take the best of all.
 *
 * Note that we don’t need to sort the edges again in point (3). So, the overall time
 * taken will be O(E log E + VE).
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

typedef struct Edge {
    int u, v, w;
    Edge(int u, int v, int w): u(u), v(v), w(w) {}
} Edge;

using VE = vector<Edge>;

bool operator ==(const Edge &e, const Edge &o)
{
    return e.u == o.u && e.w == o.w;
}

bool operator <(const Edge &e, const Edge &o)
{
    return e.w < o.w;
}

typedef struct UnionFind {
    vector<int> parents;

    UnionFind(int n): parents(n, 0) {
        iota(parents.begin(), parents.end(), 0);
    }

    int find(int u) {
        int p = parents[u];
        while (u != p) {
            u = p;
            p = parents[p];
        }
        return p;
    }

    void unite(int u, int v) {
        parents[find(u)] = find(v);
    }
} UnionFind;

int mst(int n, const VE &edges, VE *out = nullptr, const Edge *excluded = nullptr)
{
    UnionFind f(n);
    int cost = 0;
    int mstSize = 0;
    auto it = edges.begin();

    while (it != edges.end() && mstSize != n - 1) {
        if (excluded != nullptr && *excluded == *it) {
            ++it;
            continue;
        }

        int pu = f.find(it->u);
        int pv = f.find(it->v);
        if (pu != pv) {
            cost += it->w;
            ++mstSize;
            f.unite(pu, pv);
            if (out != nullptr) {
                out->emplace_back(it->u, it->v, it->w);
            }
        }
        ++it;
    }

    // It can happen that after we remove an edge, the graph is no more connected
    // and we cannot buid a MST. See sample input -> test case 1 -> edge (2, 3).
    // In that case, we return a very big value with cannot be a valid anwser.
    return (mstSize == n - 1 ? cost : 1000000000);
}

int main()
{
    int n, m;
    int u, v, w;
    int mstCost, altCost;
    vector<Edge> edges, mstEdges;

    while (scanf("%d %d\n", &n, &m) == 2) {
        for (int j = 0; j < m; ++j) {
            scanf("%d %d %d\n", &u, &v, &w);
            edges.emplace_back(u - 1, v - 1, w);
        }

        sort(edges.begin(), edges.end());
        mstCost = mst(n, edges, &mstEdges);
        altCost = 1000000000;
        for (const auto &e: mstEdges) {
            altCost = min(altCost, mst(n, edges, nullptr, &e));
        }
        printf("%d\n", altCost == 1000000000 ? mstCost : altCost);

        edges.clear();
        mstEdges.clear();
    }

    return 0;
}

