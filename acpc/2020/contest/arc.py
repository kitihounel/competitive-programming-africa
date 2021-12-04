from math import ceil

t = int(input())
for _ in range(t):
    n, k = (int(token) for token in input().split())
    q = [int(token) for token in input().split()]
    q.append(max(q) - 360)
    q.sort()

    m = []
    for j in range(1, n + 1):
        gap = q[j] - q[j-1]
        arc = (360 - gap) / k
        m.append(ceil(arc))

    print(min(m))
