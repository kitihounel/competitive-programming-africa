from math import cosh, sinh, fabs, fmod

def find_catenary_constant(d, p, initial_value=None):
    """Find the value of the catenary constant, given p and d using Newton-Raphson method."""
    a = initial_value if initial_value is not None else 2.1
    eps = 0.1
    while eps > 0.000001:
        v = d / (2.0 * a)
        g = a + p - 4.2 - a * cosh(v)
        gprime = 1.0 + v * sinh(v) - cosh(v)
        b = a - g / gprime
        eps = fabs(a - b)
        a = b
    return a

def check_initial_value(a):
    """Check if a given initial value of 'a' in Newton-Raphson method will always lead to a solution, regardless of the values of p and d.

    After some tests, we found that 2.1 gives good results.
    """
    err = False
    p = 4.3
    while p <= 10.0 and not err:
        d = 6.0
        while d <= 30.0:
            print("Checking for p={:.3f} and d={:.3f}".format(p, d))
            try:
                find_catenary_constant(d, p, a)
            except ArithmeticError as e:
                print("Error for p={:.3f}, d={:.3f} and init={:.3f}".format(p, d, a))
                err = True
                break
            d += 0.05
        p += 0.05

    if not err:
        print("Initial value of {} for a passed all tests.".format(a))


tokens = input().split(maxsplit=1)
while len(tokens) != 1:
    p, d = (float(token) for token in tokens)
    a = find_catenary_constant(d, p)
    l = (2.0 * a * sinh(d / (2.0 * a)))
    print("{:.3f}".format(l - fmod(l, 0.001)))
    tokens = input().split(maxsplit=1)
