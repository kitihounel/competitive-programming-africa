"""Solution to problem Recursively Palindromic Partitions from BCPC 2009.

The function that generates partitions of a integer was found on the page:
http://code.activestate.com/recipes/218332-generator-for-integer-partitions/

The function that geneates permutations of a list (by J. F. Sebastian) was
found at:
https://stackoverflow.com/questions/4223349/python-implementation-for-next-permutation-in-stl
"""
from math import factorial
from collections import Counter
from functools import reduce
from operator import mul, floordiv as div

def partitions(n):
    if n == 0:
        yield []
        return
    # Modify partitions of n-1 to form partitions of n
    for p in partitions(n - 1):
        yield [1] + p
        if p and (len(p) < 2 or p[1] > p[0]):
            yield [p[0] + 1] + p[1:]

def is_palindromic(p):
    if len(p) <= 1:
        return True
    return all(p[i] == p[len(p) - 1 - i] for i in range(div(len(p) ,2)))

def is_recursively_palindromic(p):
    if len(p) <= 1:
        return True
    else:
        return is_palindromic(p) and is_recursively_palindromic(p[0:div(len(p), 2)])

def palindrome_count(p):
    """Compute the number of palindromes we can form with the elements of p.
    """
    c = Counter(p)
    halves = [div(v, 2) for v in c.values() if v > 1]
    singleCount = sum([1 for v in c.values() if v % 2 == 1])
    num = factorial(sum(halves))
    denom = reduce(mul, map(factorial, halves), 1)
    return 0 if singleCount > 1 else div(num, denom) * max(1, singleCount)

def next_permutation(a):
    # Find the largest i such that a[i] < a[i + 1]. If no such index exists,
    # the permutation is the last permutation.
    i = next((i for i in reversed(range(len(a) - 1)) if a[i] < a[i + 1]), None)
    if i is not None:
        # Find the largest index j greater than i such that a[i] < a[j]
        j = next(j for j in reversed(range(i + 1, len(a))) if a[i] < a[j])
        # Swap the value of a[i] with that of a[j]
        a[i], a[j] = a[j], a[i]
        # Reverse sequence from a[i + 1] up to and including the final element a[n]
        a[i + 1:] = reversed(a[i + 1:])
        return True
    return False

for t in range(1, int(input()) + 1):
    n = int(input())
    ans = 0
    for p in filter(lambda p: palindrome_count(p) != 0, partitions(n)):
        ans += 1 if is_recursively_palindromic(p) else 0
        while next_permutation(p):
            ans += 1 if is_recursively_palindromic(p) else 0
    print(t, ans)
