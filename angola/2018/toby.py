"""This solution uses BFS to find the connected components of the graph"""
from collections import defaultdict
from operator import floordiv as div

def visit(u, a, visited):
    visited[u] = True
    for v in (j for j in a[u] if not visited[j]):
        visit(v, a, visited)

T = int(input())
for t in range(T):
    N, M = (int(token) for token in input().split())
    a = defaultdict(list)
    for j in range(M):
        u, v = (int(token) for token in input().split())
        a[u-1].append(v - 1)
        a[v-1].append(u - 1)

    visited = [False] * N
    k = 0
    for u in (j for j in range(N) if not visited[j]):
        k += 1
        visit(u, a, visited)
    print(div(k * (k - 1), 2))
