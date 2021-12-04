def to_cartesian_coordinates(s):
    return int(s[1]) - 1, ord(s[0]) - ord('a')

t = int(input())
for _ in range(t):
    wk, wh, bk = map(to_cartesian_coordinates, input().split())
    bk_zone = [
        (bk[0] + 1, bk[1] - 1), (bk[0] + 1, bk[1]), (bk[0] + 1, bk[1] - 1),
        (bk[0], bk[1] - 1), (bk[0], bk[1] + 1),
        (bk[0] - 1, bk[1] - 1), (bk[0] - 1, bk[1]), (bk[0] + 1, bk[1] + 1) 
    ]
    print('NO' if wh in bk_zone else 'YES')
