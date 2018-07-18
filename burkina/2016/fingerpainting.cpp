/**
 * This problem can be solved with a greedy algorithm.
 * Explaination of the algorithm used.
 *  1. Compute for each color the number of bottle needed.
 *  2. The maximum of those numbers give the minimum number of kit to buy.
 *  3. Compute for each color the remaining quantity and store them in an array A.
 *  4. Now if the required gray quantity is 0, we are done.
 *  5. Sort the array A in decreasing order
 *  6. Take the 3 first values of the array A.
 *  7. If they are all greater than 1, decrease each of them and the gray quantity by 1.
 *  8. If anyone is less than one, buy another kit and increase all values in A by 50.
 *  9. Go to 4.
 *
 * An improvement can be made at step 7. Instead of decreasing the values by 1, we can
 * decrease them by the value at 3rd position in A, i.e. A[2].
 *
 * Another variant of the algorithm (which we don't recommend to use), is given in the
 * file fingerpainting.alt.c.
 *
 * Note:
 *  1. In the loop that starts at point (4) of the algorithm, it is important to decrease
 *     the values by 1, any other value (50 by example) will yield to a wrong answer.
 *  2. This program is written in C++ because we don't want to suffer with C sorting
 *     function which is not really user-friendly.
 *  3. This program is really fast. It takes 0.003s on a computer with an Intel Core I5
 *     processor to solve the secret test case.
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

const int MAX_N = 12;

inline bool isEnough(const int &q)
{
    return q >= 1;
}

inline int decrease(const int &q)
{
    return q - 1;
}

inline int increase(const int &q)
{
    return q + 50;
}

int main()
{
    int needs[MAX_N], kits[MAX_N], unused[MAX_N];
    int n, g, k;

    scanf("%d", &n);
    while (n != 0) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", needs + j);
            kits[j] = needs[j] / 50 + (needs[j] % 50 != 0 ? 1 : 0);
        }
        scanf("%d", &g);

        k = *max_element(kits, kits + n);
        for (int j = 0; j < n; ++j) {
            unused[j] = k * 50 - needs[j];
        }

        while (g > 0) {
            sort(unused, unused + n, greater<int>());
            if (all_of(unused, unused + 3, isEnough)) {
                --g;
                transform(unused, unused + 3, unused, decrease);
            } else {
                ++k;
                transform(unused, unused + n, unused, increase);
            }
        }

        printf("%d\n", k);
        scanf("%d", &n);
    }

    return 0;
}

