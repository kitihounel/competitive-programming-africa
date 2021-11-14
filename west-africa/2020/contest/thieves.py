from collections import deque
from sys import stderr

def is_valid(i, j):
    global N, M
    return 0 <= i < N and 0 <= j < N

def is_on_side(i, j):
    global N, M
    return i == 0 or i == N-1 or j == 0 or j == M-1

N, M, T = (int(token) for token in input().split())
grid = [input() for _ in range(N)]
costs = [int(token) for token in input().split(maxsplit=T-1)]
for i, row in enumerate(grid):
    j = row.find("R")
    if j != -1:
        break

if is_on_side(i, j):
    print(-1)
    exit()

visited = { (i, j) }
q = deque(visited)
total_cost = 0
possible = True
blocked = [] # Used for debugging.

while q and possible:
    i, j = q.popleft()
    ch = grid[i][j]
    if ch == "." or ch == "R":
        if is_on_side(i, j):
            possible = False
        else:
            neighbors = [(i, j-1), (i, j+1), (i-1, j), (i+1, j)]
            for cell in filter(lambda cell: is_valid(*cell) and cell not in visited, neighbors):
                q.append(cell)
                visited.add(cell)
    else:
        total_cost += costs[ord(ch)-ord("a")]
        cell = (i,j)
        blocked.append(cell)

print(total_cost if possible else -1)
print(blocked, file=stderr)
