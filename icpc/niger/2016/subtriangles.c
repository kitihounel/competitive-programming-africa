/**
 * Solution provided by the Programming Competence Group of IMSP (Institut de
 * mathématiques et de sciences physiques - Dangbo(Benin)).
*/
#include <stdio.h>

int main()
{
    int p;
    long long int l;

    scanf("%d\n", &p);
    while (p > 0) {
        scanf("%lld\n", &l);
        printf("%lld\n", l * l);
        --p;
    }

    return 0;
}
