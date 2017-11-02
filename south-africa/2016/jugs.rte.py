"""This program got `Runtime Error` on ICPC Live Archive."""

from sys import stdin, setrecursionlimit
from collections import defaultdict
from heapq import heappop, heappush

class Node:
    def __init__(self, state, d):
        self.state, self.d = state, d

    def __lt__(self, other):
        return self.d < other.d

def generate(s: tuple):
    global capacities, goal, n, possible, states

    states.add(s)
    for i, c in enumerate(s):

        # If the jug is not empty, empty it.
        if c != 0:
            t = tuple(s[k] if k != i else 0 for k in range(n))
            possible = possible or goal in t
            neighbors[s].add(t)
            if t not in states:
                generate(t)

        # If the jug is not full, fill it.
        if c != capacities[i]:
            t = tuple(s[k] if k != i else capacities[i] for k in range(n))
            possible = possible or goal in t
            neighbors[s].add(t)
            if t not in states:
                generate(t)

        # Pour water in other jugs.
        for j in range(n):
            if j == i:
                continue
            m = min(c, capacities[j] - s[j])
            t = tuple(s[k] if k not in (i, j) else c - m if k == i else s[j] + m for k in range(n))
            possible = possible or goal in t
            neighbors[s].add(t)
            if t not in states:
                generate(t)

def shortest_path(start):
    global goal
    d, p, q = 0, list(), set()
    heappush(p, Node(start, 0))
    while len(p) > 0:
        u = heappop(p)
        if goal in u.state:
            d = u.d
            break
        q.add(u.state)
        for v in filter(lambda v, s=q: v not in s, neighbors[u.state]):
            heappush(p, Node(v, u.d + 1))
    return d

setrecursionlimit(20000)
for line in stdin:
    data = [int(token) for token in line.split()]
    n = data[0]
    if n == -1:
        break
    goal, capacities = data[1], tuple(data[2:])
    if goal > max(capacities):
        d = -1
    else:
        neighbors, states, possible = defaultdict(set), set(), False
        s = tuple([0]) * n
        generate(s)
        d = shortest_path(s) if possible else -1
    print(d)
