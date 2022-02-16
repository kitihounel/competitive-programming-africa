from math import gcd

def _gcd(ls):
    """Find the GCD of a sequence of numbers"""
    d = ls[0]
    for i in range(1, len(ls)):
        v = ls[i]
        d = gcd(d, v)
        if d == 1:
            break
    return d

def all_divisors(n):
    """Find all divisors of an integer"""
    divisors = [1]
    d = 2
    while d * d <= n:
        q, m = divmod(n, d)
        if m == 0:
            divisors.append([q, m] if q != m else [q])
    if n != 1:
        divisors.append(n)
    return divisors

t = int(input())
for _ in range(t):
    n, m = (int(token) for token in input().split(maxsplit=1))
    a = [int(token) for token in input().split(maxsplit=n-1)]

    adjacent_diff = [a[i] - a[i-1] for i in range(1, len(a))]
    divisors = all_divisors(_gcd(adjacent_diff))

    k = 0
    for d in divisors:
        u = sum(v // d - 1 for v in adjacent_diff)
        p = m - u
        if p >= 0:
            k += p + 1
    print(k)
