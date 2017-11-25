from sys import stdin
from collections import deque

def generate(state: tuple, depth: int):
    global capacities, goal, n, queue, states

    for i, capacity in enumerate(state):
        # If the jug is not empty, empty it.
        if capacity != 0:
            t = tuple(state[k] if k != i else 0 for k in range(n))
            if goal in t:
                return depth + 1
            elif t not in states:
                states.add(t)
                queue.append((t, depth + 1))
            else:
                pass

        # If the jug is not full, fill it.
        if capacity != capacities[i]:
            t = tuple(state[k] if k != i else capacities[i] for k in range(n))
            if goal in t:
                return depth + 1
            elif t not in states:
                states.add(t)
                queue.append((t, depth + 1))
            else:
                pass

        # Pour water in other jugs.
        for j in filter(lambda j, i=i: j != i, range(n)):
            m = min(capacity, capacities[j] - state[j])
            t = tuple(state[k] if k not in (i, j) else capacity - m if k == i \
                        else state[j] + m for k in range(n))
            if goal in t:
                return depth + 1
            elif t not in states:
                states.add(t)
                queue.append((t, depth + 1))
            else:
                pass

for line in stdin:
    data = [int(token) for token in line.split()]
    n = data[0]
    if n == -1:
        break
    goal, capacities = data[1], tuple(data[2:])
    answer = None
    if goal <= max(capacities):
        states = set()
        queue  = deque()
        start  = (0,) * n
        states.add(start)
        queue.append((start, 0))
        while queue and answer is None:
            answer = generate(*queue.popleft())
    print(answer if answer is not None else -1)
