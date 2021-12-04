from itertools import chain

t = int(input())
for _ in range(t):
    n = int(input())
    items = [int(token) for token in input().split(maxsplit=n-1)]
    even_indexes, odd_indexes = [], []
    for i, v in enumerate(items):
        ls = even_indexes if v % 2 == 0 else odd_indexes
        ls.append(i)
    even_items = sorted((items[i] for i in even_indexes), reverse=True)
    odd_items = sorted((items[i] for i in odd_indexes), reverse=True)
    tuples = sorted(chain(zip(even_indexes, even_items), zip(odd_indexes, odd_items)))
    print(*(t[1] for t in tuples))
