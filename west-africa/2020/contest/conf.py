from collections import defaultdict
from heapq import heapify, heappop, heappush

N = int(input())
dependents = defaultdict(list)
durations = []
indegrees = []
for v in range(N):
    tokens = input().split()
    durations.append(int(tokens[0]))
    for j in range(2, len(tokens)):
        u = int(tokens[j]) - 1
        dependents[u].append(v)
    indegrees.append(len(tokens) - 2)

q = [(-durations[u], u) for u in range(N) if indegrees[u] == 0]
program = []
while len(q) != 0:
    _, u = heappop(q)
    program.append(u)
    for v in dependents[u]:
        indegrees[v] -= 1
        if indegrees[v] == 0:
            heappush(q, (-durations[v], v))

print(max(i + durations[s] for i, s in enumerate(program)))
