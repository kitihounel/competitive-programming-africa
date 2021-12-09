from collections import Counter

t = int(input())
for _ in range(t):
    _, c = input(), Counter(int(token) for token in input().split())
    n = sum(v // 2 for v in c.values()) // 2
    print(n)
