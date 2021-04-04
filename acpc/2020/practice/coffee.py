def index(size):
    return 0 if size == "small" else 1 if size == "medium" else 2

t = int(input())
for _ in range(t):
    c, p = (int(token) for token in input().split(maxsplit=1))
    d = {}
    for _ in range(c):
        tokens = input().split(maxsplit=3)
        coffee_name = tokens[0]
        d[coffee_name] = tuple(int(tokens[i]) for i in (1, 2, 3))

    delivery_fees = 100 // p
    for _ in range(p):
        name, size, coffee_name = (token for token in input().split(maxsplit=2))
        i = index(size)
        price = d[coffee_name][i] + delivery_fees
        m = price % 5
        price += -1 if m == 1 else 1 if m == 4 else 0
        print(name, price) 
