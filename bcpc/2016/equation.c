/**
 * Easy problem, but there is a big trap. We can not use built-in division
 * operator to compute x because it will generate precision error. But we can
 * use integer division to compute the integer part of x and modulo operator to
 * compute the fractional part of x. See the code if you don't get it.
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int p, t;
    int a, b, c;
    int integerPart, fractionalPart;

    t = 1;
    scanf("%d\n", &p);
    while(p > 0) {
        scanf("%dx + %d = %d\n", &a, &b, &c);

        printf("Equation %d\n", t);
        if(a == 0 && c - b == 0) {
            printf("More than one solution.\n");
        } else if(a == 0 && c - b != 0) {
            printf("No solution.\n");
        } else {
            integerPart  = (c - b) / a;
            fractionalPart = abs(c - b) % a * 1000000 / a;
            printf("x = %d.%06d\n", integerPart, fractionalPart);
        }
        printf("\n");

        ++t;
        --p;
    }

    return 0;
}

