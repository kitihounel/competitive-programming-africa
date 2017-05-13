from sys import stdin

def generate():
    N = 40000
    l = []
    numbers = list(range(2, N + 1))
    while len(numbers) > 0:
        m = numbers[0]
        l.append(m)
        # Thank to Alex Marteli for the tip about using numbers[:]
        # stackoverflow.com/questions/1352885/remove-elements-as-you-traverse-a-list-in-python
        numbers[:] = [j for i, j in enumerate(numbers) if i % m != 0]
    return l

lucky = generate()
for line in stdin:
    i = int(line)
    if i != 0:
        print(lucky[i - 1])
