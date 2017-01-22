# The solution is to compute the factorial of the number, transform it into
# a string, sort the string, remove the leading zeros, and print the remaining
# string.
from math import factorial

n = int(input())
while n > 0:
    x = int(input())
    s = str(factorial(x))
    print( str().join( sorted(s) ).lstrip("0") )
    n = n - 1
