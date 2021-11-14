from math import ceil

t = int(input())
for _ in range(t):
    speed, dragon_speed, p, x, h, z = (int(token) for token in input().split())
    time = ceil((z - p) / speed)
    dragon_time = ceil(z / dragon_speed)
    if time <= dragon_time:
        ans = 0
    else:
        n = ceil((time - dragon_time) / h)
        ans = n if n <= x else 'Impossible'
    print(ans)
