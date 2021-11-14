t = int(input())
for _ in range(t):
    n = int(input())
    g = (input().split() for _ in range(n))
    winner = max(g, key=lambda item: int(item[1]))
    print(winner[0])
