def solve(s):
    count, start, seen = 0, 0, {}
    for i, ch in enumerate(s):
        if ch in seen and seen[ch] >= start:
            n = i - start
            k = seen[ch] - start
            count += n * (k + 1) - k * (k + 1) // 2
            start = seen[ch] + 1
        seen[ch] = i
    n = len(s) - start
    count += n * (n + 1) // 2
    return count

t = int(input())
for _ in range(t):
    _, s = input(), input()
    print(solve(s))
