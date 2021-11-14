from collections import Counter
from string import ascii_lowercase

w = input()
c = Counter(w)
g = (c[ch] for ch in ascii_lowercase)
print(*g)
print("".join(sorted(w)))
