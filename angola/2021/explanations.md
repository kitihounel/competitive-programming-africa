# Explanations

- [Problem A](#problem-a-look-carefully)
- [Problem B](#problem-b-eslam)
- [Problem C](#problem-c-rotten-apples)
- [Problem E](#problem-e-yassers-permutation)
- [Problem F](#problem-f-strings-wings)
- [Problem L](#problem-l-divisibility-by-two)
## Problem A: Look Carefully

Very hard problem... :)

## Problem B: Eslam

The problem asks to find the smallest multiple of $30$ with $N$ digits.

Something worth noting is that positive powers of $10$ are all congruent to $10$ modulo $30$.
It follows that ($10^n - 10$) is always a multiple of $30$, so is ($10^n + 20$).
Hence, the smallest multiple of $30$ with $N$ digits is $10^{(N-1)} + 20$.

## Problem C: Rotten Apples

Let k be the smallest dimension of the box, i.e. $k = min(m, n)$.

To get the minimum number of contamined apples, you need to arrange the rotten apples along the
smallest dimension of the box. That way, each rotten apple will only spoil one good apple. So
if the rotten apples are aligned horizontally, each rotten apple will only spoil the apple below it.
And if they are aligned vertically, each rotten apple will only spoil the apple to its right.

So there will be $\lfloor x / k \rfloor$ contamined apples if $x$ is a multiple of $k$ and
$\lfloor x / k \rfloor + 1$ otherwise. There is one more contamined apple in the last case because
the last rotten apple will spoil two good apples.

## Problem E: Yasser's Permutation

This problem is easy, you just need to know how one can generate the tuples of a cartesian product
in your preferred language.

## Problem F: Strings Wings

Given two strings $S$ and $T$ of length $N$, we have to find the minimum length of a string that has
$S$ as a prefix and $T$ as a suffix.

To get that length, we need to find the length of $U$, the longest prefix of $T$ that is also that
is also a suffix of $S$. This can be easily found with the prefix function used by the KMP algotrithm.

The answer to the problem will be $|S|$ + $|T|$ - $|U|$.

## Problem G: Parallel Universe

Disclaimer: we can't guarantee than the solution we provide for this problem is correct since we did not
have secret judge inputs.

## Problem L: Divisibility by Two.

This problem asks to find the greatest power of $2$ that is least or equal to a given number $N$.

Let $B$ be the number of bits needed to represent $N$ in binary. The power of $2$ we are
looking is then $2^{B-1}$.

Note: in the code, we use a well-known trick to check if a positive number $N$ is a power
of $2$. If $N$  is a power of $2$, then `(N & (N-1)) == 0` is true.
