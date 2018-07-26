/**
 * This problem is not solved yet, but you should read what follows.
 * We thought that the problem is about Alcuin's sequence, but it is not.
 * For a given number N, the Nth number in Alcuin's sequence give the number
 * of triangles with integer sides and perimeter N.
 *
 * For more information about Alcuin's sequence:
 *  - Alcuin's sequence on the On-line Encyclopedia of Integer Sequences (OEIS):
 *    https://oeis.org/A005044
 *  - The page where we found the formula:
 *    https://catmentor.wordpress.com/2015/01/06/no-of-triangles-when-perimeter-is-mentioned/
 *  - A discussion on Quora for the brute force algorithm:
 *    https://www.quora.com/How-do-you-find-a-total-list-of-all-triangles-with-a-given-perimeter-integer-side-lengths-by-hand
 *
 * You can also read this thread on SO:
 * https://stackoverflow.com/questions/19835174/how-to-check-if-3-sides-form-a-triangle-in-c
 */
#include <stdio.h>
#include <math.h>

int max(int a, int b)
{
    return a < b ? b : a;
}

int solveWithBruteForce(int p)
{
    int count = 0;

    for (int a = 1; a <= p / 3; ++a) {
        int b = max(a, (p - 2 * a) / 2 + 1);
        int c = p - a - b;
        while (c >= b) {
            // fprintf(stderr, "%d = %d + %d + %d\n", p, a, b, c);
            ++count;
            ++b;
            --c;
        }
    }

    return count;
}

int solveWithFormula(int p)
{
    long double f;
    
    if (p % 2 == 0) {
       f = (long double) (p * p) / 48;
    } else {
        f = (long double) ((p + 3) * (p + 3)) / 48;
    }

    return (int) llroundl(f);
}

int main()
{
    int p, k, t;

    scanf("%d\n", &t);
    while (t != 0) {
        scanf("%d %d\n", &k, &p);
        printf("%d %d %d\n", k, solveWithBruteForce(p), solveWithFormula(p));
        --t;
    }

    return 0;
}

