from math        import gcd
from functools   import reduce
from operator    import mul, floordiv as div
from sys         import stdin
from collections import Counter

def factorize(n: int) -> Counter:
    i, c = 2, Counter()
    while i * i <= n:
        while n % i == 0:
            n = div(n, i)
            c[i] += 1
        i += (i & 1) + 1
    if n != 1:
        c[n] += 1
    return c

for line in stdin:
    n = int(line)
    if n != -1:
        f = factorize(n)
        b = reduce(gcd, f.values())
        a = reduce(mul, (k ** div(v, b) for k, v in f.items()))
        print("{}^{}".format(a, b))
