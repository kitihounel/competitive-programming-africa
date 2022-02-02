from math import floor, log2

n = int(input())
p = n if (n & (n - 1)) == 0 else 2 ** floor(log2(n))
print(p)
