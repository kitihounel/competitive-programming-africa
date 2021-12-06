from itertools import chain

t = int(input())
for _ in range(t):
    n = int(input())
    numbers = [int(token) for token in input().split(maxsplit=n-1)]
    even_indexes, odd_indexes = [], []
    for i, v in enumerate(numbers):
        ls = even_indexes if v % 2 == 0 else odd_indexes
        ls.append(i)

    even_numbers = sorted((numbers[i] for i in even_indexes), reverse=True)
    odd_numbers = sorted((numbers[i] for i in odd_indexes), reverse=True)
    a = [None] * n
    for i, v in chain(zip(even_indexes, even_numbers), zip(odd_indexes, odd_numbers)):
        a[i] = v

    print(*a)
