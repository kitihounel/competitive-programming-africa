n = int(input())
while n != -1:
    a = [int(token) for token in input().split()]
    possible = (n >= 2 and a[0] % 2 == 0 and a[-1] % 2 == 0)
    if possible:
        lo, hi = 0, n - 1
        for j in range(lo, hi):
            if a[j] % 2 == a[j+1] % 2 == 0:
                possible = True
                break
        else:
            possible = False
    print("yes" if possible else "no")
    n = int(input())
