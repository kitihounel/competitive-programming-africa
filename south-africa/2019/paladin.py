from operator import floordiv as div

def cost(c1, c2):
    d = abs(ord(c1) - ord(c2))
    return min(d, 26 - d)

s = input()
while s != "-1":
    n = len(s)
    m = div(n, 2)
    a = s[0:m]
    b = s[-1:-m:-1] if n % 2 == 0 else s[-1:-m-1:-1]
    ans = sum(cost(c1, c2) for c1, c2 in zip(a, b))
    print(ans)
    s = input()
