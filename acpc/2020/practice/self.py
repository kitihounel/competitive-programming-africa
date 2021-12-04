from collections import Counter

t = int(input())
for _ in range(t):
    a = [int(ch) for ch in input()]
    c = Counter(a)
    self_describing = all(c[i] == d for i, d in enumerate(a))
    print('{}self-describing'.format('not ' if not self_describing else ''))
