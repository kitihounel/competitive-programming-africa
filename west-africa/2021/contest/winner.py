from collections import Counter

n = int(input())
a = [int(token) for token in input().split(maxsplit=n-1)]
c = Counter(a)
print("Mike" if c[1] > c[2] else "Jack" if c[2] > c[1] else "Tie")
