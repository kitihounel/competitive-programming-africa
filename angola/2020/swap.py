t = int(input())
for _ in range(t):
    _, p = input(), [int(token) for token in input().split()]
    k = sum(1 if i == v else 0 for i, v in enumerate(p, 1))
    print(k // 2 + k % 2)
