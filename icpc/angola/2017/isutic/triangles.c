#include <stdio.h>

int main()
{
    int a, b, c;
    const char *s;

    scanf("%d %d %d\n", &a, &b, &c);
    if (a + b + c != 180) {
        s = "Error";
    } else if (a == b && a == c) {
        s = "Equilateral";
    } else if (a == b || a == c || b == c) {
        s = "Isosceles";
    } else {
        s = "Scalene";
    }
    printf("%s\n", s);

    return 0;
}
