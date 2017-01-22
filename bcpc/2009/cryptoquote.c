/**
 * The only `difficulty` (note the quotes) in this problem is to find
 * the substitute of a char appearing in the encoded message. Given the mapping
 * array, the index `i` of the substitute of a character `c` is simply:
 *              i = c - 'A'
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char msg[256];
    char mapping[27];
    int  i, n;

    scanf("%d\n", &n);
    for (i = 0; i < n; ++i) {
        scanf("%[A-M N-Z]\n%s\n", msg, mapping);

        char *tmp = msg;
        while (*tmp != '\0') {
            if (!isspace(*tmp)) {
                *tmp = mapping[(*tmp - 'A')];
            }
            ++tmp;
        }

        printf("%d %s\n", i + 1, msg);
    }

    return 0;
}
