from math import ceil, floor

n = int(input())
tokens = input().split(maxsplit=n-1)
a = [int(token) - i for i, token in enumerate(tokens, 1)]
m = sum(a) / n
lo, hi = floor(m), ceil(m)
x = sum(abs(v - lo) for v in a)
y = sum(abs(v - hi) for v in a)
print(min(x, y))
