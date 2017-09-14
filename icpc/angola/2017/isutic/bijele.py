valid = [1, 1, 2, 2, 2, 8]
board = [int(token) for token in input().split()]
print(*(a - b for a, b in zip(valid, board)))
