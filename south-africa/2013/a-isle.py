from sys import stdin
from functools import cmp_to_key
from collections import namedtuple
from operator import itemgetter


colinear, counter_clockwise, clockwise = 0, -1, 1
Point = namedtuple('Point', ['x', 'y'])


def orientation(a, b, c):
    v = (c.y - b.y) * (b.x - a.x) - (b.y - a.y) * (c.x - b.x)
    return counter_clockwise if v > 0 else clockwise if v < 0 else colinear


def distance(p, q):
    return (p.x - q.x) ** 2 + (p.y - q.y) ** 2


def make_cmp(lo_point):
    """Create comparator used in convex hull function to sort points by polar angle."""
    def cmp(p, q):
        o = orientation(lo_point, p, q)
        return o if o != 0 else distance(lo_point, p) - distance(lo_point, q)
    return cmp 


def convex_hull(points: list):
    """Find convex hull of a given set of 2d-points using Graham scan.
    
    The list should contain at least three points and there should be no duplicate.
    Each point is a tuple of two integers.
    """
    lo_point = min(points, key=itemgetter(1, 0))
    cmp = make_cmp(lo_point)
    points.sort(key=cmp_to_key(cmp))
    assert lo_point is points[0]

    a = [lo_point]
    for j in range(1, len(points) - 1):
        if orientation(lo_point, points[j], points[j+1]) != colinear:
            a.append(points[j])
    a.append(points[-1])

    if len(a) <= 3:
        return a

    h = [a[0], a[1], a[2]]
    for j in range(3, len(a)):
        p = a[j]
        while len(a) > 1 and orientation(h[-2], h[-1], p) != counter_clockwise:
            h.pop()
        h.append(p)

    return h


n = int(stdin.readline())
while n != -1:
    points = []
    for _ in range(n):
        t = map(float, stdin.readline().split())
        points.append(Point(*t))
    h = convex_hull(points)
    print(len(h))
    n = int(stdin.readline())
