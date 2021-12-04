t = int(input())
for _ in range(t):
    n = int(input())
    a = [(len(token), int(token)) for token in input().split(maxsplit=n-1)]
    a.sort(key=lambda t: (t[0], -t[1]))
    print(a[-1][1])
