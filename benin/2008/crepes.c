/**
 * This is a classic problem in computer science.
 * You should really read the following articles and try to implement your own
 * solution before looking at the solution offered here:
 * https://en.wikipedia.org/wiki/Pancake_sorting
 * http://www.geeksforgeeks.org/pancake-sorting/
 * https://www.researchgate.net/publication/223925415_On_the_problem_of_sorting_burnt_pancakes
 *
 * The solution implemented here is recursive. It is verty simple and will do
 * the work with at most 3n - 2 flips.
 * The algorithm starts with the whole stack.
 * 1. Locate the largest pancake in the stack and bring it at the top by
 *    flipping the stack which it supports.
 * 2. If the up side of the pancake is not burnt, flip it.
 * 3. Now, flip the hole stack.
 * 4. Restart the process with the stack minus the current largest pancake.
 *    which is at its final position.
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * Flip the stack of pancakes. Signs should be flipped in the process.
 */
void flip(int n, int a[])
{
    int l, tmp;

    /* The middle element in the stack should be flipped to. If n is odd, */
    /* we make sure that the middle element won't be ignored in the loop. */
    l = n / 2 + (n % 2);
    for (int i = 0; i < l; ++i) {
        int j = n - 1 - i;
        tmp   =  a[j];
        a[j]  = -a[i];
        a[i]  = -tmp;
    }
}

/**
 * Locate the largest pancake (the number with the greatest magnitude)in stack.
 */
int findMax(int n, int a[])
{
    int i, m;

    i = 0;
    m = abs(a[0]);
    for (int j = 1; j < n; ++j) {
        if (abs(a[j]) > m) {
            m = abs(a[j]);
            i = j;
        }
    }
    
    return i;
}

/**
 * Sort the pancakes with at most 3n - 2 flips.
 * We stay in the bounds of 3n - 2 flips because at the end of the sorting
 * processing, when the smaller pancake will be on the top of the stack,
 * we will need to flip it at most one time.
 */
int burntPancakeSort(int n, int a[], int flips[])
{
    int i;
    int flipCount = 0;
    
    if (n == 0) {
        return flipCount;
    }

    i = findMax(n, a);
    if (i >= 1) {
        /* We bring the larger pancake at the top of the stack. We only do */
        /* that if the larger pancake is not already at the top. */
        flip(i + 1, a);
        flips[flipCount] = i + 1;
        ++flipCount;
    }

    if (n > 1) {
        if (a[0] > 0) {
            /* Flip the top pancake if its up side is not burnt. */
            a[0] = -a[0];
            flips[flipCount] = 1;
            ++flipCount;
        }

        /* We bring back the top (larger) pancake at its final position. */
        flip(n, a);
        flips[flipCount] = n;
        ++flipCount;
    } else {
        /* There is only one pancake in the stack. Flip it if its up side */
        /* is not burnt. */
        if (a[0] < 0) {
            a[0] = -a[0];
            flips[flipCount] = 1;
            ++flipCount;
        }
    }
    
    return flipCount + burntPancakeSort(n - 1, a, flips + flipCount);
}

int main()
{
    int n, m;
    int a[30], flips[88];
    int flipCount;
    
    scanf("%d\n", &n);
    for (int t = 1; t <= n; ++t) {
        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            scanf("%d", a + i);
        }
        
        flipCount = burntPancakeSort(m, a, flips);
        printf("%d %d", t, flipCount);
        for (int i = 0; i < flipCount; ++i) {
            printf(" %d", flips[i]);
        }
        printf("\n");
    }

    return 0;
}

