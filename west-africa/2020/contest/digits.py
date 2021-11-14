m = {"0": "O", "1": "I", "2": "Z", "3": "E", "5": "S", "7": "L", "8": "B", "9": "G"}
table = str.maketrans(m)
T = (int(input()))
for _ in range(T):
    s = "".join(reversed(input()))
    print(s.translate(table))
