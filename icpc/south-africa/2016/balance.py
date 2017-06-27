from sys       import stdin
from functools import reduce
from math      import gcd
from operator  import floordiv as div

def lcm(a: int, b: int) -> int:
    return div(a, gcd(a, b)) * b

for line in stdin:
    data = line.split()
    if len(data) != 2:
        break
    n, a = (int(token) for token in data)
    ans  = reduce(lcm, range(n - a, n + 1))
    print(ans)
