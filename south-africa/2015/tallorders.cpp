/**
 * This problem can be solved using Newton-Raphson method to find the zero
 * of a function.
 * The solution implemented here is described in an article of the
 * Undergraduate Journal of Mathematical Modeling: One + Two. The article is
 * contained in the file `article.pdf`. We advice to read the article before
 * diving in the code below.
 *
 * Note: This program got `Wrong Answer` on ICPC Live Archive.
 */
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

long double f(long double a, long double d, long double p)
{
    long double v = d / (2.0l * a);
    long double s = p - 4.2l;

    return (a + s - cosh(v) * a);
}

long double g(long double a, long double d)
{
    long double v = d / (2.0l * a);

    return (1.0l - cosh(v) + v * sinh(v));
}

/*
 * This function computes the value of the catenary parameter `a`, given `p`
 * and `d`, with an error of 0.00001 using the Newton-Raphson method.
 */
long double newtonRaphson(long double d, long double p)
{
    long double a, b, eps;

    /* In the document where we found the solution, a is set to 20 ft.  */
    /* 1 ft = 0.304 m and 20 ft = 6.08 m. But we choose to set a = 10.  */
    a = 10.0l;
    eps = 1.0l;
    while(eps > 0.00001l) {
        b = a - f(a, d, p) / g(a, d);
        eps = fabs(a - b);
        a = b;
    }

    return a;
}

long double length(long double a, long double d)
{
    return 2.0l * a * sinh(d / (2.0l * a));
}

int main()
{
    long double a, d, l, p;

    while (scanf("%Lf %Lf", &p, &d) == 2) {
        a = newtonRaphson(d, p);
        l = length(a, d);
        cout.precision(3);
        cout << fixed << l << endl;
    }

    return 0;
}

