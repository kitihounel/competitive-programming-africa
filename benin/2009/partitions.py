"""Solution to problem Recursively Palindromic Partitions, from Benin 2009.

This script is just the Python version of the official solution provided in C.
The explainations are also based on the official ones. We just describe the
function a little bit. The official solution is provided in the file
`partitions.official.c`.

Before reading the explainations, it may help you to notice that, given any
natural number n, the two following sets are the same.
  A = {0, 1, 2, ..., n}
  B = {n - i, with i in A}

Let f(n) be the number of recursively palindromic partitions of n.

Special cases:
  f(0) = f(1) = 1

If n is even, we can get a recursively palindromic partition by putting any
even number k <= n in the center and then a recursively palindromic partition
of (n-k)/2 on either side.
  f(n) = f((n-0)/2) + f((n-2)/2) + f((n-4)/2) + ... + f((n-n)/2)
  f(n) = f(n/2) + f((n-2)/2) + f((n-4)/2) + ... + f(0)
  f(n) = f(0) + f(2) + f(4) + ... + f((n-2)/2) + f(n/2)
Given that
  f(0) + f(2) + f(4) + ... + f((n-2)/2) = f(n-2)
we can conclude that
  f(n) = f(n-2) + f(n/2)
Note that the above formula works when n = 2.

If n is odd, we can get a recursively palindromic partition by putting any odd
number k <= n in the center and then a recursively palindromic partition of
(n-k)/2 on either side.
  f(n) = f((n-1)/2) + f((n-3)/2) + ... + f((n-n)/2)
  f(n) = f((n-1)/2) + f((n-3)/2) + ... + f(0)
let m  = n - 1. n being odd, m is even.
  f(n) = f(m/2) + f((m-2)/2) + ... + f(0)
  f(n) = f(m)

Finally
  f(n) = f(n-2) + f(n/2) if n is even
  f(n) = f(n-1) if n is odd
"""
from operator import floordiv as div

l = [1 if i <= 1 else 0 for i in range(1001)]
for i in range(2, 1001):
    l[i] = l[i - 2] + l[div(i, 2)] if i % 2 == 0 else l[i - 1]
t = int(input())
for j in range(1, t + 1):
    print(j, l[int(input())])
