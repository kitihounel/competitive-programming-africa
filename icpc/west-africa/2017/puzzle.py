from itertools   import chain, product
from copy        import deepcopy
from collections import Counter
from operator    import getitem

h, w = 5, 6

def push_light(p, i, j):
    p[i][j] = 1 - p[i][j]
    fn = lambda t: 0 <= getitem(t, 0) < h and 0 <= getitem(t, 1) < w
    for x, y in filter(fn, [(i, j - 1), (i, j + 1), (i - 1, j), (i + 1, j)]):
        p[x][y] = 1 - p[x][y]

def light_chase(p):
    actions = []
    fn = lambda i, j: getitem(getitem(p, i), j) == 1
    for i, j in filter(lambda t: fn(*t), product(range(0, h - 1), range(0, w))):
        actions.append((i + 1, j))
        push_light(p, i + 1, j)
    return actions

def check_puzzle(p):
    return not any(chain(*p))

n = int(input())
for t in range(n):
    p = [[int(token) for token in input().split()] for i in range(h)]
    a = light_chase(p)
    if not check_puzzle(p):
        for i in range(1, 64):
            b = [(0, j) for j in range(0, w) if i & (1 << j) != 0]
            c = deepcopy(p)
            for l in b:
                push_light(c, *l)
            b += light_chase(c)
            if check_puzzle(c):
                a += b
                break
    m = Counter(a)
    for k in product(range(0, h), range(0, w)):
        i, j = k
        p[i][j] = m[k] % 2
    print("PUZZLE #{}".format(t + 1))
    for row in p:
        print(*row)
