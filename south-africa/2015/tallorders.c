/**
 * This problem can be solved using Newton-Raphson method to find the zero
 * of a function.
 * The solution implemented here is described in an article of the
 * Undergraduate Journal of Mathematical Modeling: One + Two. The article is
 * contained in the file `article.pdf`. We advice to read the article before
 * diving in the code below.
 */
#include <stdio.h>
#include <math.h>

double f(double a, double d, double p)
{
    double v = d / (2 * a);
    double s = p - 4.2;

    return (a + s - cosh(v) * a);
}

double g(double a, double d)
{
    double v = d / (2.0 * a);

    return (1 - cosh(v) + v * sinh(v));
}

/*
 * This function computes the value of the catenary parameter `a`, given `p`
 * and `d`, with an error of 0.0001 using the Newton-Raphson method.
 */
double newtonRaphson(double d, double p)
{
    double a, b, eps;

    /* In the document where we found the solution, a is set to 20 ft. */
    /* 1 ft = 0.304 m and 20 ft = 6.08 m which is round to 6.5. */
    a = 6.5;
    eps = 1.0;
    while(eps > 0.0001) {
        b = a - f(a, d, p) / g(a, d);
        eps = fabs(a - b);
        a = b;
    }

    return a;
}

double length(double a, double d)
{
    return 2 * a * sinh(d / (2 * a));
}

int main()
{
    double a, d, l, p;

    while (scanf("%lf %lf", &p, &d) == 2) {
        a = newtonRaphson(d, p);
        l = length(a, d);
        printf("%.3lf\n", l);
    }

    return 0;
}

