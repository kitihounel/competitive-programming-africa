from collections import defaultdict
from sys import stderr

t = int(input())
for _ in range(t):
    n, k = tuple(int(token) for token in input().split())
    houses = [int(token) for token in input().split(maxsplit=n-1)]

    print(f'#debug> original array: {houses}', file=stderr)

    total_cost = 0
    start = 0
    for loop in range(k-1):
        print(f'#debug> step {loop + 1}', file=stderr)

        indexes = defaultdict(list)
        for i, v in enumerate(houses[start:], start):
            indexes[v].append(i)

        best, min_cost = -1, 10 ** 8
        for v, ls in indexes.items():
            cost = 0
            current_index = start
            for i in ls:
                cost += i - current_index
                current_index += 1
            if cost <= min_cost:
                best = v
                min_cost = cost
            print(f'#debug> swaps needed for {v}: {cost}', file=stderr)

        print(f'#debug> best choice: {best} with {min_cost} swap(s)', file=stderr)
        c = len(indexes[best])
        houses[:] = houses[0:start] + [best] * c +  [v for v in houses[start:] if v != best]
        total_cost += min_cost
        start += c
        print(f'#debug> new array: {houses}', file=stderr)

    print(f'#debug> total number of swap: {total_cost}', file=stderr)
    print(total_cost)
