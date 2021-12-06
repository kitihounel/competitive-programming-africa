t = int(input())
for _ in range(t):
    n = int(input())
    q, r = divmod(n, 2)
    print(q, q + r)
