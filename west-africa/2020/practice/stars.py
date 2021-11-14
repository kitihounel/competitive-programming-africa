from sys import stdin

def is_leap_year(y):
    return (y % 400 == 0) or (y % 4 == 0 and y % 100 != 0)

readline = stdin.readline
T = int(readline())
for _ in range(T):
    a, b = (int(token) for token in readline().split(maxsplit=1))
    x = (a // 400) + (a // 4) - (a // 100)
    y = (b // 400) + (b // 4) - (b // 100)
    ans = y - x + (1 if is_leap_year(a) else 0)
    print(ans)
