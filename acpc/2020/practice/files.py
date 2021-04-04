t = int(input())
for _ in range(t):
    n = int(input())
    d = {}
    for _ in range(n):
        tokens = input().split(maxsplit=1)
        name = tokens[0]
        i = int(tokens[1])
        if name in d:
            i = min(d[name], i)
        d[name] = i
    print(*sorted(d.values()))
