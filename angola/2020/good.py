def solve(s):
    count, start, seen = 0, 0, {}
    for i, ch in enumerate(s):
        if ch in seen and seen[ch] >= start:
            n = seen[ch] - start + 1
            count += (n * i) - (n * start) - (n * (n - 1) // 2)
            start = seen[ch] + 1
        seen[ch] = i
    n = len(s) - start
    count += n * (n + 1) // 2
    return count

t = int(input())
for _ in range(t):
    _, s = input(), input()
    print(solve(s))
