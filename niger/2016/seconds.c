/**
 * Solution provided by the Programming Competence Group of IMSP (Institut de
 * mathématiques et de sciences physiques - Dangbo(Benin)).
 */
#include <stdio.h>

int main()
{
    int p;
    int h, m, s, t;

    scanf("%d\n", &p);
    while (p > 0) {
        scanf("%d:%d:%d\n", &h, &m, &s);

        t = h * 3600 + m * 60 + s;
        printf("%02d:%02d:%02d equals to %d seconds\n", h, m, s, t);

        --p;
    }

    return 0;
}

