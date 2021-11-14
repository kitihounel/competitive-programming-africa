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
            root = r
        else:
            root = x
        return root

    def union_all(self, *objects):
        roots = [self[x] for x in objects]
        heaviest = max([(self.weights[r], r) for r in roots])[1]
        for r in roots:
            if r != heaviest:
                self.weights[heaviest] += self.weights[r]
                self.parents[r] = heaviest
        return heaviest

def find_spanning_tree(edges):
    ds = UnionFind()
    tree = []
    for e in edges:
        u, v, _ = e
        p, q = ds[u], ds[v]
        if p != q:
            ds.union(p, q)
            tree.append(e)
    return tree

def split_tree(tree, bridge):
    ds = UnionFind()
    costs = defaultdict(int)
    for edge in filter(lambda edge: edge[0:2] != bridge, tree):
        u, v, w = edge
        p, q = ds[u], ds[v]
        if p != q:
            s = costs[p] + costs[q]
            r = ds.union(p, q)
            costs[r] = s + w
    return ds, costs

def visit(u, visited, parents, disc, low, bridges):
    global time, neighbors
    visited.add(u)
    disc[u] = time # pylint: disable=used-before-assignment
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
    bridges = set()
    # Since the graph is connected, we can run only one DFS.
    visit(1, set(), {}, {}, {}, bridges)
    return bridges


N, M = (int(token) for token in input().split(maxsplit=1))
neighbors = defaultdict(list)
edges = []
for _ in range(M):
    u, v, w = (int(token) for token in input().split(maxsplit=2))
    neighbors[u].append(v)
    neighbors[v].append(u)
    e = (min(u, v), max(u, v), w)
    edges.append(e)

time = 0
bridges = find_brigdes()
if len(bridges) == 0:
    print(-1)
    exit()

edges.sort(key=itemgetter(2))
min_span_tree = find_spanning_tree(edges)
max_span_tree = find_spanning_tree(reversed(edges))
min_diff = 10 ** 16
for bridge in bridges:
    # Min and max spanning trees of each connected component.
    min_ds, min_costs = split_tree(min_span_tree, bridge)
    max_ds, max_costs = split_tree(max_span_tree, bridge)
    # Compute difference between costs and update the overall difference.
    u, v = bridge
    min_diff = min([
        min_diff,
        abs(min_costs[min_ds[u]] - max_costs[max_ds[v]]),
        abs(min_costs[min_ds[v]] - max_costs[max_ds[u]])
    ])

print(min_diff)
