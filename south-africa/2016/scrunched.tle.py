from math import fabs, fmod, sqrt, sin, pi

def f(x):
    global a, n, v
    return a * sin(2 * pi * n * x / v)

def compute_arclength():
    x = 0
    l = 0.0
    dx = 0.0001
    while x <= v / (4 * n):
        dy = fabs(f(x) - f(x + dx))
        l += sqrt(dx * dx + dy * dy)
        x += dx
    return l


tokens = input().split(maxsplit=2)
while len(tokens) == 3:
    w, v, n = float(tokens[0]), float(tokens[1]), int(tokens[2])
    lo = 0
    hi = sqrt(w ** 2 - v ** 2) / (2 * n)
    target = w / n
    eps = 0.1
    while eps > 0.00001:
        a = (lo + hi) / 2
        l = compute_arclength() * 4
        if l >= target:
            hi = a
        else:
            lo = a
        eps = fabs(target - l)
    print("{:.3f}".format(a - fmod(a, 0.001)))
    tokens = input().split(maxsplit=2)
