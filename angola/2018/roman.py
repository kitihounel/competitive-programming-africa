def to_decimal(s):
    # https://www.geeksforgeeks.org/converting-roman-numerals-decimal-lying-1-3999/
    global DIGITS
    v, prev = 0, 0
    for ch in reversed(s):
        current = DIGITS[ch]
        if current >= prev:
            v += current
        else:
            v -= current
        prev = current
    return v

DIGITS = { "I": 1, "V": 5, "X": 10, "L": 50, "C":  100, "D": 500, "M": 1000 }
N = int(input())
for j in range(N):
    Z = to_decimal(input())
    print("{} {}".format("YES" if Z % 3 == 0 else "NO", Z))
