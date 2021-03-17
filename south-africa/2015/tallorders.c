/**
 * This problem can be solved using Newton-Raphson method to find the zero
 * of a function.
 * The solution implemented here is described in an article of the
 * Undergraduate Journal of Mathematical Modeling: One + Two. The article is
 * contained in the file 'article.pdf'. We advice to read the article before
 * looking in the code below.
 */
#include <stdio.h>
#include <math.h>

/*
 * This function computes the value of the catenary parameter 'a', given 'p'
 * and 'd', with an error of 0.00001 using the Newton-Raphson method.
 */
long double findCatenaryConstant(long double d, long double p)
{
    long double a, next, eps;
    long double g, gprime, v;

    a = 2.1L;
    eps = 1.0L;
    while(eps > 0.000001L) {
        v = d / (2.0 * a);
        g = a + p - 4.2 - a * coshl(v);
        gprime = 1.0 + v * sinhl(v) - coshl(v);
        next = a - g / gprime;
        eps = fabsl(a - next);
        a = next;
    }

    return a;
}

int main()
{
    long double d, p;
    long double a, l;

    while (scanf("%Lf %Lf\n", &p, &d) == 2) {
        a = findCatenaryConstant(d, p);
        l = 2.0L * a * sinhl(d / (2.0L * a));
        printf("%.3Lf\n", l - fmodl(l, 0.001L));
    }

    return 0;
}
