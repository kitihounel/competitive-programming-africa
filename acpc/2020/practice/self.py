from collections import Counter

t = int(input())
for _ in range(t):
    s = input()
    a = [int(ch) for ch in s]
    c = Counter(a)
    self_describing = True
    for i, d in enumerate(a):
        if c[i] != d:
            self_describing = False
            break
    print("{}self-describing".format("not " if not self_describing else ""))
