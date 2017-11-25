/**
 * We need the following def to use strcasestr.
 */
#define _GNU_SOURCE 1

#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>

/**
 * Replace all occurences of 'name' (whatever the case) that appear in 'str' by
 * 'name'.
 * But there are traps in the input. We have to check that we really find an
 * occurrence 'name'. There are two things we have to verify:
 *    * 'name' should aways be followed by a space or a punctuation.
 *    * If 'name' is not at the beginning of 'str', i.e at the beginning, of a
 *    * sentence, 'name' shoud be preceded by a space.  
 */
void replaceOccurences(char *str, char *name)
{
    int   i, len;
    char *p, ch;

    len = (int) strlen(name);
    p   = strcasestr(str, name);
    while (p != NULL) {
        if (!isspace(*(p + len)) && !ispunct(*(p + len))) {
            p = strcasestr(p + len, name);
            continue;
        }
        if (p != str && !isspace(*(p - 1))) {
            p = strcasestr(p + 1, name);
            continue;
        }

        i  = p - str;
        ch = str[i + len];
        sprintf(str + i, "%s", name);
        str[i + len] = ch;
        p = strcasestr(p + len, name);
    }
}

int main()
{
    char  line[10002];

    while (fgets(line, 10002, stdin) != NULL && line[0] != '#') {
        replaceOccurences(line, "ERIC");
        replaceOccurences(line, "BLOW");
        replaceOccurences(line, "AMAGBEGNON");
        printf("%s", line);
    }
    printf("%c\n", '#');

    return 0;
}
