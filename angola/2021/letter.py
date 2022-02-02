from itertools import product

s = input()
g = [[c.upper(), c] if c.islower() else [c, c.lower()] if c.isupper() else [c] for c in s]
for t in product(*g):
    print(''.join(t))
