from sys import stdin

print(len({int(line) % 42 for line in stdin}))
