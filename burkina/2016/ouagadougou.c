#include <stdio.h>
#include <string.h>

int main()
{
    char  line[501];
    char *p;
    
    fgets(line, 501, stdin);
    while (line[0] != '#') {
        p = strstr(line, "Ouagadougou");
        while (p != NULL) {
            memmove(p + 5, p + 11, strlen(p + 11) + 1);
            p = strstr(p + 5, "Ouagadougou");
        }
        printf("%s", line);
        fgets(line, 501, stdin);
    }
    
    return 0;
}

