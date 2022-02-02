def prefix_fn(s):
    p = [0 for _ in range(len(s))]
    for i in range(1, len(s)):
        j = p[i-1]
        while j > 0 and s[i] != s[j]:
            j = p[j-1]
        if s[i] == s[j]:
            j += 1
        p[i] = j
    return p

n, s, t = int(input()), input(), input()
a = prefix_fn(t + '#' + s)
print(len(s) + len(t) - a[-1])
