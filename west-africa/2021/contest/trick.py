x, y = (int(token) for token in input().split(maxsplit=1))
print(max(x + y, x * y, x - y, y - x))
