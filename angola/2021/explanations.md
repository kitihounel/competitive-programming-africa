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

**Disclaimer**: we can't guarantee that our solution is correct since we did not test it with judge inputs
(we did not have them).

Given an array of length $N$ that contains $K (K \leq 20)$ differents integers, we should group similar values together using the minimum number of adjacent swaps. Sorting the array is not the best solution, since it will
not always yield to the minimum number of swaps. For example, with the array $[3, 3, 1, 1, 2, 1, 2, 2]$, the
best solution is to just swap the fifth and sixth elements. Sorting the array will involve more swaps.

Our solution uses a greedy algorithm that runs in $K-1$ steps. At each step, we compute for each integer in the
array the number of swaps needed to move all its occurrences at the beginning of the array. Then we chose the one
with the minimum cost and move all its occurrences at the beginning of the array and we restart the process with
the remaining array.

Let's explain the process with the following example: $A = [1, 2, 4, 3, 1, 1, 2, 4, 3, 5]$. We will need $4$ steps.

### Step 1
  - Number of swaps needed to move all $1s$ at the begining: $6$
  - Number of swaps needed to move all $2s$: $6$
  - Number of swaps needed to move all $3s$: $10$
  - Number of swaps needed to move all $4s$: $8$
  - Number of swaps needed to move all $5s$: $9$

The best choice is to move all $2s$ with $6$ swaps. The resulting array is $[2, 2, 1, 4, 3, 1, 1, 4, 3, 5]$.

### Step 2
  - Number of swaps needed to move all $1s$: $4$
  - Number of swaps needed to move all $4s$: $5$
  - Number of swaps needed to move all $3s$: $7$
  - Number of swaps needed to move all $5s$: $7$

The best choice is to move all $1s$ with $4$ swaps. The resulting array is $[2, 2, 1, 1, 1, 4, 3, 4, 3, 5]$.

### Step 3
  - Number of swaps needed to move all $4s$: $1$
  - Number of swaps needed to move all $3s$: $3$
  - Number of swaps needed to move all $5s$: $4$

The best choice is to move all $4s$ with one swap. The resulting array is $[2, 2, 1, 1, 1, 4, 4, 3, 3, 5]$.

### Step 4
  - Number of swaps needed to move all $3s$: $0$
  - Number of swaps needed to move all $5s$: $2$

Nothing to do at this step, the array won't change. And since we are at the fourth step, we are done.

The process is over, and we need $11$ swaps to reach our goal. 

**Note**: There is a similar problem to this one that asks to sort an array using the minimum number of adjacent
swaps. The solution is to use merge sort and count the number of swaps in the merge step.

## Problem L: Divisibility by Two.

This problem asks to find the greatest power of $2$ that is least or equal to a given number $N$.

Let $B$ be the number of bits needed to represent $N$. The power of $2$ we are looking for is
$2^{B-1}$.

Note: in the code, we check if $N$ is a power of two with a well-known trick. If $N$  is a power
of $2$, then `(N & (N-1)) == 0` is true.
