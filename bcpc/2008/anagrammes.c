/**
 * The solution implemented here is just to sort the two strings and to test if
 * they are equal.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib>

/**
 * Comparison function used to sort strings with qsort.
 */
int compare(const void *p1, const void *p2)
{
    return *((char *) p1) - *((char *) p2);
}

/**
 * Use this comparison function if the char type is unsigned on your system.
 */
int xcompare(const void *p1, const void *p2)
{
    int a = (int) *((char *) p1);
    int b = (int) *((char *) p2);

    return a - b;
}

int main()
{
    int   n;
    char  s[66], t[66];

    scanf("%d\n", &n);
    while (n > 0) {
        scanf("%s %s\n", s, t);
        qsort(s, strlen(s), sizeof(char), compare);
        qsort(t, strlen(t), sizeof(char), compare);
        if (!strcmp(s, t)) {
            printf("%s et %s sont des anagrammes l'un pour l'autre\n", s, t);
        } else {
            printf("%s et %s ne sont pas des anagrammes l'un pour l'autre\n", \
                   s, t);
        }

        --n;
    }

    return 0;
}

