/**
 * The solution is to determine the intersection of the two input strings, i.e.
 * characters that belong to both strings. Note that a character can appear
 * several times in the intersection.
 * The anagramic distance between the two strings is then:
 *      sum of lengths of the two strings - 2 * length of the intersection.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Comparison function used to sort strings by qsort.
 */
int compare(const void *p1, const void *p2)
{
    return *((char *) p1) - *((char *) p2);
}

/* Use this comparison function if the char type is unsigned on your system. */
int xcompare(const void *p1, const void *p2)
{
    int a = (int) *((char *) p1);
    int b = (int) *((char *) p2);

    return a - b;
}

/**
 * Compute the length of the intersection of two sorted strings.
 *
 * The algorithm used looks a lot like the mergesort algorithm. We look over
 * the two strings and compare elements at current positions.
 *      - If the elements are equal, we increment the size of the intersection
 *        and we advance of one postion in the two strings.
 *      - Else we advance of one postion in the string with the smaller element.
 *
 * We stop when we reach the end of one the two strings.
 */
size_t intersection_length(const char *s1, const char *s2)
{
    size_t l = 0;
    
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 == *s2) {
            ++l;
            ++s1;
            ++s2;
        } else {
            if (*s1 > *s2) {
                ++s2;
            } else {
                ++s1;
            }
        }
    }

    return l;
}

int main()
{
    char s1[66], s2[66];
    int  i, n;
    size_t  l1, l2;

    scanf("%d\n", &n);
    for (i = 0; i < n; ++i) {
        scanf("%s\n%s\n", s1, s2);

        // We need to sort the string in order to determine the intersection.
        l1 = strlen(s1);
        l2 = strlen(s2);
        qsort(s1, l1, sizeof(char), compare);
        qsort(s2, l2, sizeof(char), compare);

        printf("Cas #%d: %zu\n", i + 1, \
               l1 + l2 - 2 * intersection_length(s1, s2));
    }

    return 0;
}

