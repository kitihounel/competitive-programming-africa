def lay_h(x, box, m):
    q = x // m
    for i in range(q):
        box[i] = ['*'] * m
    r = x % m
    if r != 0:
        box[q][:r] = ['*'] * r

def lay_v(x, box, n):
    q = x // n
    for row in box:
        row[:q] = ['*'] * q
    r = x % n
    if r != 0:
        for row in box[0:r]:
            row[q] = '*'

t = int(input())
for _ in range(t):
    n, m, x = (int(token) for token in input().split())

    box = [['.'] * m for _ in range(n)]
    if n > m:
        lay_h(x, box, m)
    else:
        lay_v(x, box, n)

    for row in box:
        print(''.join(row))
