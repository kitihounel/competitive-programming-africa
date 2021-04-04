from itertools import takewhile

t = int(input())
for _ in range(t):
    s = input()
    n = 0
    for ch in takewhile(lambda ch: ch == "U", s):
        n += 1
    print(n)
