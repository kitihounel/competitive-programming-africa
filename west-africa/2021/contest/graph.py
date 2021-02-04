from collections import defaultdict
from operator import itemgetter

class UnionFind:
    def __init__(self):
        self.weights = {}
        self.parents = {}

    def __getitem__(self, i):
       # Check for previously unknown object.
        if i not in self.parents:
            self.parents[i] = i
            self.weights[i] = 1
            return i

        # Find path of objects leading to the root.
        path = [i]
        root = self.parents[i]
        while root != path[-1]:
            path.append(root)
            root = self.parents[root]

        # Compress the path and return.
        for ancestor in path:
            self.parents[ancestor] = root
        return root

    def union(self, i, j):
        x, y = self[i], self[j]
        if x != y:
            r, d = (x, y) if self.weights[x] > self.weights[y] else (y, x)
            self.weights[r] += self.weights[d]
            self.parents[d] = r

    def union_all(self, *objects):
        roots = [self[x] for x in objects]
        heaviest = max([(self.weights[r], r) for r in roots])[1]
        for r in roots:
            if r != heaviest:
                self.weights[heaviest] += self.weights[r]
                self.parents[r] = heaviest

time = 0

def visit(u, visited, parents, disc, low, bridges):
    global time, neighbors

    visited.add(u)
    disc[u] = time
    low[u] = time
    time += 1
    for v in neighbors[u]:
        if v not in visited:
            parents[v] = u
            visit(v, visited, parents, disc, low, bridges)
            low[u] = min(low[u], low[v])
            if low[v] > disc[u]:
                b = (min(u, v), max(u, v))
                bridges.add(b)
        elif v != parents[u]:
            low[u] = min(low[u], disc[v])
        else:
            pass

def find_brigdes():
    global neighbors

    bridges = set()
    # Since the graph is connected, we can run only ons DFS.
    visit(1, set(), {}, {}, {}, bridges)
    return bridges

N, M = (int(token) for token  in input().split(maxsplit=1))
neighbors = defaultdict(list)
edges = []
for _ in range(M):
    u, v, w = (int(token) for token  in input().split(maxsplit=2))
    neighbors[u].append(v)
    neighbors[v].append(u)
    e = (min(u, v), max(u, v), w)
    edges.append(e)

bridges = find_brigdes()
if len(bridges) == 0:
    print(-1)
    exit()

edges.sort(key=itemgetter(2))
min_diff = 10 ** 16
for b in bridges:
    # Min spanning trees construction.
    min_ds = UnionFind()
    min_tree_costs = defaultdict(int)
    for u, v, w in edges:
        if (u, v) == b:
            continue
        p, q = min_ds[u], min_ds[v]
        if p != q:
            s = min_tree_costs[p] + min_tree_costs[q]
            min_ds.union(p, q)
            min_tree_costs[min_ds[p]] = s + w

    # Max spanning trees construction.
    max_ds = UnionFind()
    max_tree_costs = defaultdict(int)
    for u, v, w in reversed(edges):
        if (u, v) == b:
            continue
        p, q = max_ds[u], max_ds[v]
        if p != q:
            s = max_tree_costs[p] + max_tree_costs[q]
            max_ds.union(p, q)
            max_tree_costs[max_ds[p]] = s + w

    u, v = b
    min_diff = min([
        min_diff,
        abs(min_tree_costs[min_ds[u]] - max_tree_costs[max_ds[v]]),
        abs(min_tree_costs[min_ds[v]] - max_tree_costs[max_ds[u]])
    ])

print(min_diff)
