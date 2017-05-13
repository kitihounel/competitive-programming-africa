#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int   n;
    char  name[257], surname[257];
    char *p;

    scanf("%d\n", &n);
    while (n != 0) {
        scanf("%s %s\n", name, surname);
        p = surname;
        while (*p != 0) {
            *p = tolower(*p);
            ++p;
        }
        name[0] = tolower(name[0]);
        printf("%c%s@mapcom-group.com\n", name[0], surname);
        --n;
    }

    return 0;
}
