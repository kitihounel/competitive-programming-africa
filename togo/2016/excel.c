#include <stdio.h>

int main()
{
    int  l, m, n;
    char ch;
    char col[7];

    while(scanf("R%dC%d\n", &n, &m) > 0 && n > 0) {

        /* Get the column by converting m is base 26. */
        /* Since the input numbers are numbered from 1, we should substract */
        /* 1 from m in each loop. */
        l = 0;
        do {
            --m;
            ch = (m % 26) + 'A';
            m /= 26;
            col[l] = ch;
            ++l;
        } while(m > 0);
        col[l] = '\0';

        /* Reverse the column digits to put them in the right order. */
        for (int i = 0; i < l / 2; ++i) {
            ch = col[i];
            col[i] = col[l - 1 - i];
            col[l - 1 - i] = ch;
        }

        printf("%s%d\n", col, n);
    }
}

