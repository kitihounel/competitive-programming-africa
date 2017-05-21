#include <stdio.h>
#include <string.h>

int main()
{
    int  p;
    char haystack[5], needle[3];
    
    scanf("%d\n", &p);
    while (p > 0) {
        scanf("%s %*s %s BF\n", needle, haystack);
        printf("%sfunny plate\n", strstr(haystack, needle) == NULL? "not a ": "");
        --p;
    }
    
    return 0;
}
